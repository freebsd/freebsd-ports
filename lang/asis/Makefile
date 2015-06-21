# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asis
PORTVERSION=	2014
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-gpl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT implementation of Ada Semantic Interface Specification

LICENSE=	GPLv2

BUILD_DEPENDS=	gprbuild>=20130416:${PORTSDIR}/devel/gprbuild \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		${GUSTATIC}:${PORTSDIR}/lang/gnat_util
RUN_DEPENDS=	${GUSTATIC}:${PORTSDIR}/lang/gnat_util

USES=		ada gmake
NO_MTREE=	yes
MAKE_ENV=	PROCESSORS=${MAKE_JOBS_NUMBER}
GUSTATIC=	${LOCALBASE}/lib/gnat_util/libgnat_util.a

post-extract:
	@${REINPLACE_CMD} -e 's|OPSYS|ASISOPSYS|g' \
		-e 's|(prefix)|(DESTDIR)$$(prefix)|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/Makefile.stub \
		${WRKSRC}/common.gpr
	@${REINPLACE_CMD} -e 's|Hostparm.OpenVMS|False|' \
		${WRKSRC}/asis/a4g-a_types.adb \
		${WRKSRC}/tools/gnatmetric/asis_ul-env* \
		${WRKSRC}/tools/tool_utils/asis_ul-environment.adb \
		${WRKSRC}/tools/tool_utils/asis_ul-projects.adb \
		${WRKSRC}/tools/tool_utils/asis_ul-common.adb \
		${WRKSRC}/tools/gnatpp/gnatpp-processing.adb \
		${WRKSRC}/tools/gnatpp/gnatpp-output.ad[sb]

	@${RM} -rf ${WRKSRC}/gnat

do-build:
	# This target is recreated because -j cannot be set, but
	# MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} all)

post-install:
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
		${SORT} >> ${TMPPLIST})

.include <bsd.port.mk>
