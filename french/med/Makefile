# New ports collection makefile for:	med
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	med
DISTVERSION=	2.3.6
PORTREVISION=	3
CATEGORIES=	french science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modelisation et Echanges de Donnees

BUILD_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
LIB_DEPENDS=	hdf5.6:${PORTSDIR}/science/hdf5-18
RUN_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

TK_VER?=	8.5
SHORT_TK_VER=	${TK_VER:S/.//}

USE_FORTRAN=	yes
FFLAGS+=	-O2

CONFIGURE_ENV=	HDF5HOME=${LOCALBASE} CPPFLAGS="${PTHREAD_CFLAGS}"	\
		LDFLAGS="${PTHREAD_LIBS}" WISH=${LOCALBASE}/bin/wish${TK_VER}
CONFIGURE_ARGS=	--with-f90=${FC} --docdir=${DOCSDIR}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes

DOC2FIX=	. gif html jpg png tests
TST2FIX=	c f

PORTDOCS=	*
PORTEXAMPLES=	*

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

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
