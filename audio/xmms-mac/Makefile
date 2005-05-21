# New ports collection makefile for:	xmms-mac
# Date Created:				23 February 2005
# Whom:					<arundel@h3c.de>
#
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mac-port
PKGNAMEPREFIX=	xmms-
DISTNAME=	xmms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	arundel@h3c.de
COMMENT=	Monkey's Audio Codec non-win32 port

BUILD_DEPENDS=	mac:${PORTSDIR}/audio/mac
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CPPFLAGS=${CPPFLAGS}
USE_AUTOCONF_VER=	259
CPPFLAGS+=	"-I${LOCALBASE}/include"

PLIST_FILES=	lib/xmms/Input/libxmms-mac.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libxmms-mac.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
