# New ports collection makefile for:	xmms-timidity
# Date created:		2009-01-05
# Whom:			Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$

PORTNAME=	xmms-timidity
PORTVERSION=	0.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.shikadi.net/utils/files/

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	XMMS input plugin to play midi files (via timidity)

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_LDCONFIG=	${PREFIX}/lib/xmms/Input

USE_GCC=	3.4
USE_BZIP2=	yes
USE_GNOME=	gtk12
CFLAGS+=	`glib-config --cflags` -g -fPIC

FILES=	xmms-timidity.cpp
PLIST_FILES=	lib/xmms/Input/libxmms-timidity.so

do-build:
	(cd ${WRKSRC} && ${CXX} ${CFLAGS} -c ${FILES} -o xmms-timidity.o)

.include <bsd.port.mk>
