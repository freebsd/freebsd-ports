# New ports collection makefile for:	daimonin-client
# Date created:				15 Feb 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	daimonin_client
DISTVERSION=	BETA3-0966
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	daimonin
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Free open source Massively Multiplayer On-line Role-playing Game (MMORPG)

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/share/${PORTNAME}
USE_SDL=	mixer image
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/daimonin/client/make/linux

post-patch:
	@${CHMOD} a+x ${WRKSRC}/configure
	@${CP} ${PORTSDIR}/Templates/config.guess ${PORTSDIR}/Templates/config.sub \
		${WRKSRC}/make_utils/

post-install:
	@${ECHO} "cd ${PREFIX}/share/${PORTNAME} && ./daimonin" > ${PREFIX}/bin/daimonin
	@${CHMOD} a+x ${PREFIX}/bin/daimonin

.include <bsd.port.mk>
