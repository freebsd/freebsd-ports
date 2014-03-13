# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asis
PORTVERSION=	2011
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-gpl-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT implementation of Ada Semantic Interface Specification

LICENSE=	GPLv2

BUILD_DEPENDS=	gnat_util>=2013:${PORTSDIR}/lang/gnat_util \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		${GUSTATIC}:${PORTSDIR}/lang/gnat_util
RUN_DEPENDS=	${GUSTATIC}:${PORTSDIR}/lang/gnat_util

USES=		ada gmake
NO_MTREE=	yes
MAKE_ENV=	PROCESSORS=${MAKE_JOBS_NUMBER}
GUSTATIC=	${LOCALBASE}/lib/gnat_util/libgnat_util.a

post-extract:
	@${REINPLACE_CMD} -e 's|OPSYS|ASISOPSYS|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/Makefile.stub \
		${WRKSRC}/common.gpr
	@${RM} -rf ${WRKSRC}/gnat

do-build:
	# This target is recreated because -j cannot be set, but
	# MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_ARGS} all

post-install:
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | \
	   ${SORT} -r | ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' \
	   -e '/share\/gps$$/d' -e '/share\/gps\/plug-ins$$/d' \
	   -e 's/^/@dirrm /g' >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
