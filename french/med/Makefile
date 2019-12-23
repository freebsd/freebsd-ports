# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	med
DISTVERSION=	4.0.0
CATEGORIES=	french science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Modelisation et Echanges de Donnees

LICENSE=	GPLv3

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		fortran gmake libtool tk

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_CXXSTD=	gnu++98
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--disable-python --with-hdf5=${LOCALBASE}
CONFIGURE_ENV=	WISH=${WISH}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_WRKSRC=	${WRKSRC}/tests
TEST_TARGET=	check  # XXX: one fail
TEST_ENV=	${MAKE_ENV} HDF5_DISABLE_VERSION_CHECK=1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LIBVER=		11.0.0
PLIST_SUB+=	VE=${LIBVER}

PATCH_TK_SCRIPTS=	tools/mdump/xmdump2.in tools/mdump/xmdump3.in

DOC2FIX=	. dox gif html html.dox jpg png
TST2FIX=	c f

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

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in

post-patch-EXAMPLES-off:
	${REINPLACE_CMD} -e '/SUBDIRS/ s|tests||' ${WRKSRC}/Makefile.in

post-install:
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf mdump3 mdump	\
		&& ${LN} -sf xmdump3 xmdump)

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
