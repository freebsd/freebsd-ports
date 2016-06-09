# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asis
PORTVERSION=	2015
PORTREVISION=	2
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
PORTDOCS=	html pdf *.txt

post-extract:
	@${REINPLACE_CMD} -e 's|OPSYS|ASISOPSYS|g' \
		-e 's|(prefix)|(DESTDIR)$$(prefix)|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/Makefile.stub \
		${WRKSRC}/common.gpr
	@${RM} -rf ${WRKSRC}/gnat

do-build:
	# This target is recreated because -j cannot be set, but
	# MAKE_JOBS_UNSAFE=yes would break PROCESSORS value
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} all)

do-install:
	# gprinstall seems to be malfunctioning, just install manually
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/include/asis \
		${STAGEDIR}${PREFIX}/lib/asis \
		${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins \
		${STAGEDIR}${DOCSDIR}/html \
		${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_PROGRAM} ${WRKSRC}/tools/asistant/asistant \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asis/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/asis
	${INSTALL_DATA} ${WRKSRC}/lib/*.ali ${STAGEDIR}${PREFIX}/lib/asis
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib/asis
	${INSTALL_DATA} ${WRKSRC}/documentation/*.html \
		${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/documentation/*.pdf \
		${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/documentation/*.txt \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/asis.xml \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins
	${INSTALL_DATA} ${FILESDIR}/asis.gpr ${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
