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

int atapi_getcdtoc(int scsifd, CDTOC *cdtoc);
int atapi_cd_setblocksize(int scsifd, int bytessec);
int atapi_cdrawread(char *buffer, int startlba,
                   int blocksize, int blockstoread, int scsifd);
int atapi_cddaread(char *buffer, int startlba,
                   int blocksize, int blockstoread, int scsifd);
int atapi_begin_cdda(int scsifd);
int atapi_end_cdda(int scsifd);
int atapi_initcd(int scsifd);
int atapi_resetcd(int scsifd);
