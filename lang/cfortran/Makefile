# New ports collection Makefile for: 	cfortran
# Date created:				5 December 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	cfortran
PORTVERSION=	4.3
CATEGORIES=	lang
MASTER_SITES=	http://www-zeus.desy.de/~burow/cfortran/
DISTFILES=	cfortran.h \
		cfortran.html \
		cfortran.doc \
		cfortran.examples.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	# none

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An easy-to-use powerful bridge between C and FORTRAN

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${_DISTDIR}/${dfile} ${WRKSRC}
.endfor
	(cd ${WRKSRC} && ${TAR} -xf cfortran.examples.tar.gz)

do-install:
	${INSTALL_DATA} ${WRKSRC}/cfortran.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cfortran.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cfortran.doc ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	(cd ${WRKSRC}/eg && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
