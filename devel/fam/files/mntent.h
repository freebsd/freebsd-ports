/* -*-C++-*-

  mntent.h

  Copyright (C) 2002 Alan Eldridge
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  

  $Id$

  2002/09/08 alane@geeksrus.net
*/

#ifdef HAVE_MNTENT_H
#include <mntent.h>
#else

#ifndef mntent_h_
#define mntent_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/mount.h>

#define	MOUNTED	"dummy"
#define MNTTYPE_NFS "nfs"

const int MOPTSLEN (256 - (MNAMELEN * 2 + MFSNAMELEN + 2 * sizeof(int)));

struct mntent {
public:  
  char	mnt_fsname[ MNAMELEN ];
  char	mnt_dir[ MNAMELEN ];
  char	mnt_type[ MFSNAMELEN ];
  char	mnt_opts[ MOPTSLEN ];
  int	mnt_freq, mnt_passno;
private:
  void clear();
public:
  mntent() {
    clear();
  }
  struct mntent *from_statfs(struct statfs *pst);
};

FILE *setmntent(const char *szfn, char *szrw);
struct mntent *getmntent(FILE *pf);
char *hasmntopt(const struct mntent *pmnt, const char *szopt);
int endmntent(FILE *pf);

#endif /* mntent_h_ */
#endif /* not HAVE_MNTENT_H */
