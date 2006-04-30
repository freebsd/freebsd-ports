# New ports collection makefile for:	bmp-mac
# Date Created:		17 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	mac-port
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	infofarmer@gmail.com
COMMENT=	Monkey's Audio Codec non-win32 port

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		mac.2:${PORTSDIR}/audio/mac

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
USE_AUTOTOOLS=	autoconf:259
CPPFLAGS+=	"-I${LOCALBASE}/include"
PLUGDIR=	lib/bmp/Input
PLUGFILE=	lib${PKGNAMEPREFIX}${PORTNAME}.so
PLIST_FILES=	${PLUGDIR}/${PLUGFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/${PLUGFILE} ${PREFIX}/${PLUGDIR}/

.include <bsd.port.mk>
