# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asis
PORTVERSION=	2016
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-gpl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT implementation of Ada Semantic Interface Specification

LICENSE=	GPLv2

BUILD_DEPENDS=	gprbuild>=20130416:devel/gprbuild \
		xmlada>=3.2:textproc/xmlada \
		${GUSTATIC}:lang/gnat_util
RUN_DEPENDS=	${GUSTATIC}:lang/gnat_util

USES=		ada gmake
NO_MTREE=	yes
MAKE_ENV=	PROCESSORS=${MAKE_JOBS_NUMBER}
GUSTATIC=	${LOCALBASE}/lib/gnat_util/libgnat_util.a
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

post-extract:
	@${REINPLACE_CMD} -e 's|OPSYS|ASISOPSYS|g' \
		-e 's|(prefix)|(DESTDIR)$$(prefix)|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/Makefile.stub \
		${WRKSRC}/common.gpr
	@${RM} -r ${WRKSRC}/gnat

do-build:
	# This target is recreated because -j cannot be set, but
	# MAKE_JOBS_UNSAFE=yes would break PROCESSORS value
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} all)

do-build-DOCS-on:
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html-all)

do-install:
	# gprinstall seems to be malfunctioning, just install manually
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/include/asis \
		${STAGEDIR}${PREFIX}/lib/asis \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_PROGRAM} ${WRKSRC}/tools/asistant/asistant \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asis/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/asis
	${INSTALL_DATA} ${WRKSRC}/lib/*.ali ${STAGEDIR}${PREFIX}/lib/asis
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib/asis
	${INSTALL_DATA} ${FILESDIR}/asis.gpr ${STAGEDIR}${PREFIX}/lib/gnat

do-install-DOCS-on:
	(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
