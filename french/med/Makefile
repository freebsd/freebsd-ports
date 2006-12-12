# New ports collection makefile for:	med
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	med
PORTVERSION=	2.3.1
CATEGORIES=	french science
MASTER_SITES=	http://www.code-aster.org/FICHIERS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modelisation et Echanges de Donnees

BUILD_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5
RUN_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}

TK_VER?=	8.4
SHORT_TK_VER=	${TK_VER:S/.//}

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	HDF5HOME=${LOCALBASE} CPPFLAGS="${PTHREAD_CFLAGS}"	\
		LDFLAGS="${PTHREAD_LIBS}" WISH=${LOCALBASE}/bin/wish${TK_VER}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.if !defined(WITHOUT_F90)
F90=		gfortran41
BUILD_DEPENDS+=	${F90}:${PORTSDIR}/lang/gfortran
CONFIGURE_ARGS+=	--with-f90=${F90}
.endif

DOC2FIX=	. gif html jpg png tests
TST2FIX=	c f

.include <bsd.port.pre.mk>

.if !${OSVERSION} < 500039
F77?=		f77
.endif
FFLAGS?=	-O2

pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|SUBDIRS = src tests tools doc|SUBDIRS = src tests tools|'	\
		${WRKSRC}/Makefile.in
.endif
.for dd in ${DOC2FIX}
	@${REINPLACE_CMD} -e 's|docdir = $$(datadir)/doc|docdir = $$(datadir)/doc/@PACKAGE@|'	\
		${WRKSRC}/doc/${dd}/Makefile.in
.endfor
.for dd in ${TST2FIX}
	@${REINPLACE_CMD} -e 's|test${dd}dir = $$(bindir)/test|test${dd}dir = ${EXAMPLESDIR}/test|' \
		${WRKSRC}/tests/${dd}/Makefile.in
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

regression-test:
	@(cd ${BUILD_WRKSRC};	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
