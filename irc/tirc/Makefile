# New ports collection makefile for:        tirc IRC-Client
# Date created:		14 August 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	tirc
PORTVERSION=	1.2
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Token's 'Internet Relay Chat' Client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ansi-colours
MAKE_ARGS=	CONF_ARGS="--prefix=${PREFIX}"

MAN1=		tirc.1
PLIST_FILES=	bin/tirc %%DATADIR%%/tircrc
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/*.c ${WRKSRC}/*.1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/tirc
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dot.tircrc ${DATADIR}/tircrc

.include <bsd.port.mk>
