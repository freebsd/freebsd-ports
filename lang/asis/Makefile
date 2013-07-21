# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asis
PORTVERSION=	2011
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-gpl-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT implementation of Ada Semantic Interface Specification

BUILD_DEPENDS=	gnat_util>=2013:${PORTSDIR}/lang/gnat_util \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada

USES=		ada gmake

DESTINY=	${WRKDIR}/destino
MAKE_ENV=	DESTDIR=${DESTINY} \
		PROCESSORS=${MAKE_JOBS_NUMBER}

post-extract:
	@${REINPLACE_CMD} -e 's|OPSYS|ASISOPSYS|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/Makefile.stub \
		${WRKSRC}/common.gpr
	@${RM} -rf ${WRKSRC}/gnat

do-build:
	# This target is recreated because -j cannot be set, but
	# MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake all

post-install:
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/
	@cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${WRKDIR}/PLIST.all
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | \
	   ${SORT} -r | ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' \
	   -e '/share\/gps$$/d' -e '/share\/gps\/plug-ins$$/d' \
	   -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@${CAT} ${WRKDIR}/PLIST.all >> ${TMPPLIST}

.include <bsd.port.mk>
