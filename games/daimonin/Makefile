# New ports collection makefile for:	daimonin-client
# Date created:				15 Feb 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	daimonin_client
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	daimonin
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Free open source Massively Multiplayer On-line Role-playing Game (MMORPG)

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/share
CONFIGURE_ENV=	CFLAGS="-pipe"
USE_SDL=	mixer image
USE_XLIB=	yes
SUB_FILES=	daimonin.sh
SUB_LIST=	PORTVERSION=${PORTVERSION}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/make/linux

post-patch:
	@${CHMOD} a+x ${WRKSRC}/configure ${WRKSRC}/make_utils/install-sh
	@${CP} ${PORTSDIR}/Templates/config.guess ${PORTSDIR}/Templates/config.sub \
		${WRKSRC}/make_utils/

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/daimonin.sh ${PREFIX}/bin/daimonin
	${CHMOD} a+x ${PREFIX}/bin/daimonin

.include <bsd.port.mk>
