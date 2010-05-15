# New ports collection makefile for:	daimonin-client
# Date created:				15 Feb 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	daimonin_client
PORTVERSION=	0.9.7.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/daimonin/Client%20Sources/Client%20Source%20${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Free open source Massively Multiplayer On-line Role-playing Game (MMORPG)

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs \
		curl.6:${PORTSDIR}/ftp/curl

USE_ZIP=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/share
CONFIGURE_ENV=	CFLAGS="-pipe" LDFLAGS="-L${LOCALBASE}/lib"
USE_SDL=	mixer image
SUB_FILES=	daimonin.sh
SUB_LIST=	PORTVERSION=${PORTVERSION}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

WRKSRC=		${WRKDIR}/client/make/linux

post-patch:
	@${CHMOD} a+x ${WRKSRC}/configure ${WRKSRC}/make_utils/install-sh
	@${CP} ${PORTSDIR}/Templates/config.guess ${PORTSDIR}/Templates/config.sub \
		${WRKSRC}/make_utils/

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/daimonin.sh ${PREFIX}/bin/daimonin
	${CHMOD} a+x ${PREFIX}/bin/daimonin

.include <bsd.port.mk>
