# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	rvi
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	LOCAL/petef \
		http://www.cs.ru.ac.za/research/g98t4414/static/home/rvi/
DISTNAME=	rvi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple interface to RCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/rvi
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${WRKSRC} && ${CXX} -I. ${CXXFLAGS} -o rvi src/rvi.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rvi ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rvi.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
