# New ports collection makefile for:	xmms-mac
# Date Created:				23 February 2005
# Whom:					<arundel@h3c.de>
#
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.2.1
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
USE_AUTOCONF_VER=	259

WRKSRC=		${WRKDIR}/libxmms-mac

TARGET_DIR=	${PREFIX}/lib/xmms/Input

PROG_FILES=	${WRKSRC}/src/.libs/libxmms-mac.so.1

do-install:
	${INSTALL} -d ${TARGET_DIR}
	${INSTALL_PROGRAM} ${PROG_FILES} ${TARGET_DIR}/libxmms-mac.so

.include <bsd.port.mk>
