# New ports collection makefile for:	med
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	med
DISTVERSIONPREFIX=	full-src-
DISTVERSION=	2.3.6
DISTVERSIONSUFFIX=	.noarch
CATEGORIES=	french science
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modelisation et Echanges de Donnees

BUILD_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5
RUN_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}

ASTER_VER=	10.1.0
ASTER_DISTVERSION=	${ASTER_VER}-4
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_VER}/SRC

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

TK_VER?=	8.4
SHORT_TK_VER=	${TK_VER:S/.//}

USE_FORTRAN=	yes
FFLAGS+=	-O2

CONFIGURE_ENV=	HDF5HOME=${LOCALBASE} CPPFLAGS="${PTHREAD_CFLAGS}"	\
		LDFLAGS="${PTHREAD_LIBS}" WISH=${LOCALBASE}/bin/wish${TK_VER}
CONFIGURE_ARGS=	--with-f90=${FC} --docdir=${DOCSDIR}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
USE_LDCONFIG=	yes

DOC2FIX=	. gif html jpg png tests
TST2FIX=	c f

PORTDOCS=	*
PORTEXAMPLES=	*

post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})

pre-configure:
.for ext in am in
. if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.${ext}
. endif
. if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e '/SUBDIRS/ s|tests||' ${WRKSRC}/Makefile.${ext}
. endif
. for dd in ${DOC2FIX}
	${REINPLACE_CMD} -e 's|docdir = $$(datadir)/doc|docdir = @docdir@|'	\
		${WRKSRC}/doc/${dd}/Makefile.${ext}
. endfor
. for dd in ${TST2FIX}
	${REINPLACE_CMD} -e 's|test${dd}dir = $$(bindir)/test|test${dd}dir = ${EXAMPLESDIR}/test|' \
		${WRKSRC}/tests/${dd}/Makefile.${ext}
. endfor
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

regression-test:
	@(cd ${BUILD_WRKSRC}/tests;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
