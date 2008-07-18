# Ports collection makefile for:	ghc6-doc
# Date created:				19 Jun 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ghc
PORTVERSION=	6.8.3
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/docs/${PORTVERSION}/ \
		http://www.haskell.org/ghc/docs/${PORTVERSION}/html/
PKGNAMESUFFIX=	-doc
DISTFILES=	Cabal.html.tar.gz \
		libraries.html.tar.gz users_guide.html.tar.gz \
		index.html
DIST_SUBDIR=	ghc-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation (HTML, PS) for the Glasgow Haskell Compiler

NO_BUILD=	yes
DOCSDIR=	${PREFIX}/share/doc/ghc6
PORTDOCS=	*

do-install:
.if defined(NOPORTDOCS)
	@${ECHO} NOPORTDOCS set, nothing to do!
.else
	@${MKDIR} ${DOCSDIR}
.for FILE in index.html
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${FILE} \
		${DOCSDIR}
.endfor
.for FILE in Cabal.html.tar.gz \
	libraries.html.tar.gz users_guide.html.tar.gz
	@${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${FILE} \
		-C ${DOCSDIR}
.endfor
	@${FIND} ${DOCSDIR}/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${DOCSDIR}/ -type f -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} \;
.endif

.include <bsd.port.mk>
