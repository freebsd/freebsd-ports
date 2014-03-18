# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	ecm
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Compresses CD images by stripping unnecessary EDC/ECC data

LICENSE=	GPLv2

CONFLICTS=	gmp-ecm-[0-9]*

PLIST_FILES=	bin/ecm bin/unecm
PORTDOCS=	format.txt

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${PORTNAME} un${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
