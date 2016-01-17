# Created by: Jeffrey Hsu <hsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jam
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/jam/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Build utility like make(1)

NO_WRKSUBDIR=	yes
USES=		zip

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
