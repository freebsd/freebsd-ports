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
EXTRACT_ONLY=	# none

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An easy-to-use powerful bridge between C and FORTRAN

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${DISTDIR}/${dfile} ${WRKDIR}
.endfor

do-install:
	${INSTALL_DATA} ${WRKDIR}/cfortran.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cfortran.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cfortran.doc ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	${TAR} --strip-components 1 -xf ${WRKDIR}/cfortran.examples.tar.gz -C ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
