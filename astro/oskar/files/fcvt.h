//
// fcvt.c
//
// Floating point to string conversion routines
//
// Copyright (C) 2002 Michael Ringgaard. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.  
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.  
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
// SUCH DAMAGE.
// 

#include <math.h>
#define CVTBUFSIZE 64

//
// cvt.c - IEEE floating point formatting routines for FreeBSD
// from GNU libc-4.6.27
//

static char *cvt(double arg, int ndigits, int *decpt, int *sign, char *buf, int eflag) {
  int r2;
  double fi, fj;
  char *p, *p1;

  if (ndigits < 0) ndigits = 0;
  if (ndigits >= CVTBUFSIZE - 1) ndigits = CVTBUFSIZE - 2;
  r2 = 0;
  *sign = 0;
  p = &buf[0];
  if (arg < 0) {
    *sign = 1;
    arg = -arg;
  }
  arg = modf(arg, &fi);
  p1 = &buf[CVTBUFSIZE];

  if (fi != 0) {
    p1 = &buf[CVTBUFSIZE];
    while (fi != 0) {
      fj = modf(fi / 10, &fi);
      *--p1 = (int)((fj + .03) * 10) + '0';
      r2++;
    }
    while (p1 < &buf[CVTBUFSIZE]) *p++ = *p1++;
  } else if (arg > 0) {
    while ((fj = arg * 10) < 1) {
      arg = fj;
      r2--;
    }
  }
  p1 = &buf[ndigits];
  if (eflag == 0) p1 += r2;
  *decpt = r2;
  if (p1 < &buf[0]) {
    buf[0] = '\0';
    return buf;
  }
  while (p <= p1 && p < &buf[CVTBUFSIZE]) {
    arg *= 10;
    arg = modf(arg, &fj);
    *p++ = (int) fj + '0';
  }
  if (p1 >= &buf[CVTBUFSIZE]) {
    buf[CVTBUFSIZE - 1] = '\0';
    return buf;
  }
  p = p1;
  *p1 += 5;
  while (*p1 > '9') {
    *p1 = '0';
    if (p1 > buf) {
      ++*--p1;
    } else {
      *p1 = '1';
      (*decpt)++;
      if (eflag == 0) {
        if (p > buf) *p = '0';
        p++;
      }
    }
  }
  *p = '\0';
  return buf;
}

inline char *ecvt(double arg, int ndigits, int *decpt, int *sign) {
  char cvtbuf[CVTBUFSIZE];
  return cvt(arg, ndigits, decpt, sign, cvtbuf, 1);
}

inline char *ecvtbuf(double arg, int ndigits, int *decpt, int *sign, char *buf) {
  return cvt(arg, ndigits, decpt, sign, buf, 1);
}

inline char *fcvt(double arg, int ndigits, int *decpt, int *sign) {
  char cvtbuf[CVTBUFSIZE];
  return cvt(arg, ndigits, decpt, sign, cvtbuf, 0);
}

inline char *fcvtbuf(double arg, int ndigits, int *decpt, int *sign, char *buf) {
  return cvt(arg, ndigits, decpt, sign, buf, 0);
}

