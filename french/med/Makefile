# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	med
DISTVERSION=	3.0.6
PORTREVISION=	2
CATEGORIES=	french science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Modelisation et Echanges de Donnees

LICENSE=	GPLv3

LIB_DEPENDS=	hdf5.7:${PORTSDIR}/science/hdf5-18

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_FORTRAN=	yes
USE_TK=		yes
FFLAGS+=	-O2

CONFIGURE_ENV=	HDF5HOME=${LOCALBASE} 	\
		WISH=${WISH}
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-f90=${FC} --docdir=${DOCSDIR}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes

PATCH_TK_SCRIPTS=	tools/mdump/xmdump.in tools/mdump/xmdump3.in

DOC2FIX=	. dox gif html html.dox jpg png
TST2FIX=	c f

PORTDOCS=	*
PORTEXAMPLES=	*

NO_STAGE=	yes
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
.endfor
.for dd in ${TST2FIX}
	${FIND} ${WRKSRC}/tests -name "Makefile.*" | ${XARGS}	\
	${REINPLACE_CMD} -e 's|test${dd}dir = $$(bindir)/test|test${dd}dir = ${EXAMPLESDIR}/test|' \
			-e 's|unittestsdir = $$(bindir)/unit|unittestsdir = ${EXAMPLESDIR}/unit|' \
			-e 's|usescasesdir = $$(bindir)/uses|usescasesdir = ${EXAMPLESDIR}/uses|'
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
