/*****************************************************************************
* CDD v1.0 Copyright (C) 1996-97, Charles R. Henrich, All Rights Reserved.   *
*                                                                            *
* Use in source and binary forms, with or without modification and           *
* Redistribution without modification are permitted provided that the        *
* following conditions are met:                                              *
*                                                                            *
* 1. Redistributions of source code must retain the above copyright          *
*    notice, all internal copyright notices, this list of conditions         *
*    and the following disclaimer.                                           *
* 2. Redistributions in binary form must reproduce the above copyright       *
*    notice, this list of conditions and the following disclaimer in the     *
*    documentation and/or other materials provided with the distribution.    *
* 3. All advertising materials mentioning features or use of this software   *
*    must display the following acknowledgement:                             *
*      CDD was developed in 1996-97 by Charles Henrich                       *
* 4. Neither the name of this product (CDD) nor the name of the author       *
*    (Charles Henrich) may be used to endorse products that include this     *
*    product without specific prior written permission.                      *
* 5. No profit may be made from the inclusion, or distribution of this       *
*    product.  Although a reasonable service charge for the distribution     *
*    of this product is permitted where appropriate.                         *
*                                                                            *
* THIS SOFTWARE IS PROVIDED BY CHARLES HENRICH `` AS IS '' AND ANY EXPRESS   *
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED          *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE     *
* DISCLAIMED.  IN NO EVENT SHALL CHARLES HENRICH BE LIABLE FOR ANY DIRECT,   *
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES         *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR         *
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)         *
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT *
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF     *
* SUCH DAMAGE.                                                               *
*                                                                            *
******************************************************************************
*                                                                            *
* Email: henrich@msu.edu                                                     *
*                                                                            *
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include <unistd.h>
#include <stdlib.h>
#include "cdd.h"
#include "cdd_cdcmds.h"
#include "cdd_util.h"

#include <sys/cdio.h>

int 
atapi_cdrawread(char *buffer, int startlba, int blocksize, 
		int blockstoread, int scsifd)
{
	struct ioc_read_audio ira;

	if (blocksize/blockstoread != 2352) {
		fprintf(stderr, "Ouch, only 2352 (%d)bytes allowed\n",
			blocksize);
		return -1 ;
	}
#if 0
fprintf(stderr, "reading %d blocks at %d\n", blockstoread, startlba);
#endif

	ira.address_format = CD_LBA_FORMAT;
	ira.address.lba = startlba;
	ira.nframes = blockstoread;
	ira.buffer = buffer;

	if (ioctl(scsifd, CDIOCREADAUDIO, &ira) < 0) {
	    perror("CDIOREADAUDIO");
	    exit(-1);
	}
	return SUCCESS ;
}

int 
atapi_getcdtoc(int scsifd, CDTOC * cdtoc)
{
    struct ioc_toc_header th;
    struct ioc_read_toc_entry te;
    struct cd_toc_entry *cte;
    int i, tracks, ntracks;

    if (ioctl(scsifd, CDIOREADTOCHEADER, &th) < 0) {
	perror("CDIOREADTOCHEADER");
	exit(-1);
    }
    ntracks = th.ending_track - th.starting_track + 2;
    cte = (struct cd_toc_entry *)malloc(sizeof(*cte) * ntracks);

    tracks = ntracks ;
    if (tracks > 100)
	tracks = 101;

    te.address_format = CD_LBA_FORMAT;
    te.starting_track = 0 ;
    te.data_len = ntracks * sizeof(struct cd_toc_entry);
    te.data = cte;
 
    if (ioctl(scsifd, CDIOREADTOCENTRYS, &te) < 0) {
	perror("CDIOREADTOCENTRYS");
	exit(-1);
    }
fprintf(stderr, "toclen %d\n", cdtoc->toclen);
    cdtoc->numentries = tracks+1 ;
    cdtoc->firsttrack = th.starting_track ;
    cdtoc->lasttrack = th.ending_track ;
    for (i = 0; i <= tracks; i++) {
	cdtoc->tocents[i].absaddr = ntohl(cte[i-th.starting_track].addr.lba);
	cdtoc->tocents[i].tracknumber = cte[i-th.starting_track].track;
	if (i>0)
	    cdtoc->tocents[i-1].absendaddr =
		cdtoc->tocents[i].absaddr ;
	fprintf(stderr, "track %d %d start %8d ctrl 0x%x type 0x%x l %d\n",
	    i,
	    cte[i-th.starting_track].track,
	    ntohl(cte[i-th.starting_track].addr.lba),
	    cte[i-th.starting_track].control,
	    cte[i-th.starting_track].addr_type,
	    cdtoc->tocents[i-1].absendaddr);
    }
    return SUCCESS;
}

int 
atapi_cd_setblocksize(int scsifd, int bytessec)
{
    /* nop */
    return SUCCESS;
}

int 
atapi_cddaread(char *buffer, int startlba,
	    int blocksize, int blockstoread, int scsifd)
{
    return atapi_cdrawread(buffer, startlba, blocksize, blockstoread, scsifd);
}

int 
atapi_begin_cdda(int scsifd)
{
    return atapi_cd_setblocksize(scsifd, 2352);
}

int 
atapi_end_cdda(int scsifd)
{
    return atapi_cd_setblocksize(scsifd, 2048);
}

int 
atapi_initcd(int scsifd)
{
    return SUCCESS;
}

int 
atapi_resetcd(int scsifd)
{
    return SUCCESS;
}
