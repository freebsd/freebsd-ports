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

.include <bsd.port.options.mk>

do-install:
.for f in ${PORTNAME} un${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
