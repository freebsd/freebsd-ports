/*
 * *****************************************************************
 * *                                                               *
 * *    Copyright (c) Compaq Computer Corporation, 1999            *
 * *                                                               *
 * *   All Rights Reserved.  Unpublished rights  reserved  under   *
 * *   the copyright laws of the United States.                    *
 * *                                                               *
 * *   The software contained on this media  is  proprietary  to   *
 * *   and  embodies  the  confidential  technology  of  Compaq    *
 * *   Computer Corporation.  Possession, use,  duplication  or    *
 * *   dissemination of the software and media is authorized only  *
 * *   pursuant to a valid written license from Compaq Computer    *
 * *   Corporation.                                                *
 * *                                                               *
 * *   RESTRICTED RIGHTS LEGEND   Use, duplication, or disclosure  *
 * *   by the U.S. Government is subject to restrictions  as  set  *
 * *   forth in Subparagraph (c)(1)(ii)  of  DFARS  252.227-7013,  *
 * *   or  in  FAR 52.227-19, as applicable.                       *
 * *                                                               *
 * *****************************************************************
 */

#ifndef _ALPHA_STDARG_H_
#define _ALPHA_STDARG_H_

#include <machine/ansi.h>

#ifdef __lint__
#define __builtin_saveregs()            (0)
#define __builtin_classify_type(t)      (0)
#endif

typedef _BSD_VA_LIST_   va_list;

#define va_start(list, parmN) __builtin_va_start(list, parmN, 1)
#define va_end(list)
#define va_arg(list, mode) \
        (*((__builtin_isfloat(mode) && sizeof(mode) > sizeof(double)) ? \
           *(((list).__offset += ((int)sizeof(mode *) + 7) & -8), \
             (mode **)( ((char *)(list).__base) + (list).__offset - \
                (((int)sizeof(mode *) + 7) & -8))) : \
           (((list).__offset += ((int)sizeof(mode) + 7) & -8), \
            (mode *)( ((char *)(list).__base) + (list).__offset - \
                     ((__builtin_isfloat(mode) && (list).__offset <= (6 * 8)) ? \
                      (6 * 8) + 8 : ((int)sizeof(mode) + 7) & -8)))))

#endif /* !_ALPHA_STDARG_H_ */
