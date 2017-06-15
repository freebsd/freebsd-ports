# Created by: kris
# $FreeBSD$

PORTNAME=	mindguard
PORTVERSION=	0.0.0.4
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://zapatopi.net/mindguard/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helpful utility for detecting and jamming harmful mind-control rays

LICENSE=	MGPL
LICENSE_NAME=	MINDGUARD PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:tgz
USE_GNOME=	gtk12

ALL_TARGET=	# empty

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mindguard ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/carriers/*.carrier ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
