# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tycho
PORTVERSION=	0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
DISTNAME=	redcoder

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to gather data (statistics) on Core War warriors

USE_BZIP2=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/tycho \
		bin/tycho-exstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/exstat ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-exstat

.include <bsd.port.mk>
