# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	med
DISTVERSION=	3.0.8
PORTREVISION=	2
CATEGORIES=	french science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Modelisation et Echanges de Donnees

LICENSE=	GPLv3

LIB_DEPENDS=	libhdf5.so:science/hdf5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		fortran gmake libtool tk
CONFIGURE_ARGS=	--disable-python --with-hdf5=${LOCALBASE}
CONFIGURE_ENV=	WISH=${WISH}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PATCH_TK_SCRIPTS=	tools/mdump/xmdump2.in tools/mdump/xmdump3.in

DOC2FIX=	. dox gif html html.dox jpg png
TST2FIX=	c f

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/include/2.3.6/med_outils.h \
		${WRKSRC}/include/med_outils.h
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e '/SUBDIRS/ s|tests||' ${WRKSRC}/Makefile.in
.endif
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

post-install:
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf mdump3 mdump	\
		&& ${LN} -sf xmdump3 xmdump)

regression-test:
	(cd ${BUILD_WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
