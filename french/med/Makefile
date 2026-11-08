PORTNAME=	med
DISTVERSION=	4.2.0
CATEGORIES=	french science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Modelisation et Echanges de Donnees
WWW=		https://docs.salome-platform.org/med-4.2.0-documentation/

LICENSE=	GPLv3

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libhdf5-110.so:science/hdf5-110

USES=		fortran gmake libtool localbase python tk

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_CXXSTD=	gnu++98
CFLAGS+=	-fPIC
FCFLAGS+=	-I${LOCALBASE}/include
FFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${WISH}
CONFIGURE_ARGS=	--enable-python \
		--with-swig=${LOCALBASE} \
		--with-hdf5=${LOCALBASE} \
		--with-hdf5-include=${LOCALBASE}/include/hdf5-110

USE_LDCONFIG=	yes
TEST_WRKSRC=	${WRKSRC}/tests
TEST_TARGET=	check  # XXX: one fail
TEST_ENV=	${MAKE_ENV} HDF5_DISABLE_VERSION_CHECK=1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LIBVER=		11.1.3
PLIST_SUB+=	VE=${LIBVER}

PATCH_TK_SCRIPTS=	tools/mdump/xmdump2.in tools/mdump/xmdump3.in

DOC2FIX=	. dox gif html html.dox jpg png
TST2FIX=	c f

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/h5pcc-110)
USES+=		mpi
CFLAGS+=	${MPI_CFLAGS}
LDFLAGS+=	${MPI_LIBS}
NOMPI=		no
.else
NOMPI=		yes
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/include/2.3.6/med_outils.h \
		${WRKSRC}/include/med_outils.h
.for dd in ${DOC2FIX}
	${REINPLACE_CMD} -e 's|docdir = $$(datadir)/doc|docdir = @docdir@|'	\
		${WRKSRC}/doc/${dd}/Makefile.in
.endfor
.for dd in ${TST2FIX}
	${FIND} ${WRKSRC}/tests -name Makefile.in | ${XARGS}	\
	${REINPLACE_CMD} -e 's|test${dd}dir = $$(bindir)/test|test${dd}dir = ${EXAMPLESDIR}/test|' \
			-e 's|unittestsdir = $$(bindir)/unit|unittestsdir = ${EXAMPLESDIR}/unit|' \
			-e 's|usescasesdir = $$(bindir)/uses|usescasesdir = ${EXAMPLESDIR}/uses|'
.endfor
.if ${NOMPI} == "no"
	${REINPLACE_CMD} -e '/FreeBSD: remove if MED_HAVE_MPI/d' \
		${WRKSRC}/include/med.h.in
.endif

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in

post-patch-EXAMPLES-off:
	${REINPLACE_CMD} -e '/SUBDIRS/ s|tests||' ${WRKSRC}/Makefile.in

post-install:
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf mdump4 mdump	\
		&& ${LN} -sf xmdump4 xmdump)

.include <bsd.port.post.mk>
