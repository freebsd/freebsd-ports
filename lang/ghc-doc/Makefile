# Ports collection makefile for:	ghc6-doc
# Date created:				19 Jun 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ghc-doc
PORTVERSION=	6.4
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/docs/${PORTVERSION}/ \
		http://www.haskell.org/ghc/docs/${PORTVERSION}/html/
DISTFILES=	Cabal.ps.gz Cabal.html.tar.gz building.ps.gz \
		building.html.tar.gz hslibs.html.tar.gz \
		hslibs.ps.gz libraries.html.tar.gz users_guide.html.tar.gz \
		users_guide.ps.gz index.html
DIST_SUBDIR=	ghc-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation (HTML, PS) for the Glasgow Haskell Compiler

NO_BUILD=	yes
DOCSDIR=	${PREFIX}/share/doc/ghc6

do-install:
	@${MKDIR} ${DOCSDIR}
.for FILE in Cabal.ps.gz building.ps.gz hslibs.ps.gz users_guide.ps.gz index.html
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${FILE} \
		${DOCSDIR}
.endfor
.for FILE in Cabal.html.tar.gz building.html.tar.gz hslibs.html.tar.gz \
	libraries.html.tar.gz users_guide.html.tar.gz
	@${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${FILE} \
		-C ${DOCSDIR}
.endfor

.include <bsd.port.mk>
