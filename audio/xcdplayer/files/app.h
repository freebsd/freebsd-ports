/* $FreeBSD$ */
/*
 * Copyright (C) 1990 Regents of the University of California.
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and that
 * both that copyright notice and this permission notice appear in
 * supporting documentation, and that the name of the University of
 * California not be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior
 * permission.  the University of California makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 */

typedef struct {
  char            *file;
  char            *device;
  Boolean         debug;
  Boolean         display_timer;
  float           volbase;
  float           volpcent;
  int             replayThreshold;
  int             pauseSkipInterval;
  int             scanSkipInterval;
  float           scanPauseInterval;
  float           pausePauseInterval;
  char            *cdInfoDir;
} AppData;
