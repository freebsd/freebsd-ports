# Copyright 2000 Vladimir N.Silyaev
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification,	are permitted provided that the	following conditions
# are met:
# 1. Redistributions of	source code must retain	the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in	binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other	materials provided with	the distribution.
#
# THIS SOFTWARE	IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS	IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,	BUT NOT	LIMITED	TO, THE
# IMPLIED WARRANTIES OF	MERCHANTABILITY	AND FITNESS FOR	A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR	OR CONTRIBUTORS	BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL,	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON	ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR	TORT (INCLUDING	NEGLIGENCE OR OTHERWISE) ARISING IN ANY	WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN	IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
# $FreeBSD$
#

SYS?=		/sys
NOMAN=		YES
KMOD=		rtc
MODULE_DEPEND=	linux
CDEV_MAJOR?=	202
DEVNAME= 	${KMOD}
SRCS=		rtc.c rtc_linux.c vnode_if.h

INCLUDE=	-I${.CURDIR} -I${SYS}

CFLAGS+=	${INCLUDE} -DCDEV_MAJOR_=${CDEV_MAJOR}

all:	vnode_if.h

#afterinstall: device

device:
	rm -f /dev/${DEVNAME}
	mknod /dev/${DEVNAME} c ${CDEV_MAJOR} 0

.include <bsd.kmod.mk>
