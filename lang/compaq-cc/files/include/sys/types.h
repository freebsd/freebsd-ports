/*
 * *****************************************************************
 * *                                                               *
 * *    Copyright (c) Compaq Computer Corporation, 1999, 2000      *
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
#ifndef _CCC_SYS_TYPES_H_
#define _CCC_SYS_TYPES_H_

#ifndef __int8_t_defined
typedef long int int64_t;
typedef unsigned long int u_int64_t;
#endif

#include_next <sys/types.h>

#ifndef __BIT_TYPES_DEFINED__
#define __BIT_TYPES_DEFINED__ 1
#endif

#endif  /* _CCC_SYS_TYPES_H_ */
