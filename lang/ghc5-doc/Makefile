# Ports collection makefile for:	ghc-doc
# Date created:				26 Jul 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ghc-doc
PORTVERSION=	5.04.3
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/docs/${PORTVERSION}/ \
		http://www.haskell.org/ghc/docs/${PORTVERSION}/html/
DISTFILES=      building.html.tar.gz building.ps.gz hslibs.html.tar.gz \
		hslibs.ps.gz libraries.html.tar.gz users_guide.html.tar.gz \
		users_guide.ps.gz index.html
DIST_SUBDIR=	ghc
EXTRACT_ONLY=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation (HTML, PS) for the Glasgow Haskell Compiler

NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/doc/ghc
.for FILE in building.ps.gz hslibs.ps.gz users_guide.ps.gz index.html
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${FILE} \
		${LOCALBASE}/share/doc/ghc
.endfor
.for FILE in building.html.tar.gz hslibs.html.tar.gz \
	libraries.html.tar.gz users_guide.html.tar.gz
	@${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${FILE} \
		-C ${LOCALBASE}/share/doc/ghc
.endfor

.include <bsd.port.mk>
