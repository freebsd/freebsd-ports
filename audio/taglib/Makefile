# New ports collection makefile for:	taglib
# Date Created:				06 Nov 2003
# Whom:				 	Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	taglib
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/taglib/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Library for manipulating ID3v1 and ID3v2 tags in MP3 and OGG formats

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-extract:
	${TOUCH} ${WRKSRC}/Makefile.in

post-configure:
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>

