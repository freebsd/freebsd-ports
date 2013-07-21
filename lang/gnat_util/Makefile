# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnat_util
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSION}
DISTNAME=	gcc-${GCC_VERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Library used to build GNAT tools such as ASIS

USES=		ada
USE_BZIP2=	yes
DISTINFO_FILE=	${.CURDIR}/../gcc-aux/distinfo
WRKSRC=		${WRKDIR}/${PORTNAME}
DESTINY=	${WRKDIR}/destino
MAKE_ENV=	DESTDIR=${DESTINY} \
		MAKEOBJDIR=${WRKSRC}/obj

.include "${.CURDIR}/Makefile.sources"
.include "${.CURDIR}/../gcc-aux/Makefile.version"
.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/obj
.for F in Makefile gnat_util.gpr sdefault_adb.gnat_util
	@${CP} ${FILESDIR}/${F} ${WRKSRC}/
.endfor
.for F in ${GNAT_SRCS}
	@${CP} ${WRKDIR}/${DISTNAME}/gcc/ada/${F} ${WRKSRC}/
.endfor

post-install:
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/
	@cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${WRKDIR}/PLIST.all
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | \
	   ${SORT} -r | ${SED} -e '/lib\/gnat$$/d' -e 's/^/@dirrm /g' \
	   >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@${CAT} ${WRKDIR}/PLIST.all >> ${TMPPLIST}

.include <bsd.port.post.mk>

