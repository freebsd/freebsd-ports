# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnat_util
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR= ${MS_SUBDIR}
DISTNAME=	${IDENTIFICATION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Library used to build GNAT tools such as ASIS

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

USES=		ada tar:bzip2
NO_MTREE=	yes
DISTINFO_FILE=	${.CURDIR}/../gcc-aux/distinfo
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	MAKEOBJDIR=${WRKSRC}/obj

.include "${.CURDIR}/Makefile.sources"
.include "${.CURDIR}/../gcc-aux/Makefile.version"

post-extract:
	@${MKDIR} ${WRKSRC}/obj
.for F in Makefile gnat_util.gpr sdefault_adb.gnat_util \
	update_path.c set_std_prefix.c
	@${CP} ${FILESDIR}/${F} ${WRKSRC}/
.endfor
.for F in ${GNAT_SRCS}
	@${CP} ${WRKDIR}/${DISTNAME}/gcc/ada/${F} ${WRKSRC}/
.endfor

post-install:
	# impunit is needed for GPS menus, just provide the source files
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/gcc/ada/impunit.* \
		${STAGEDIR}${PREFIX}/include/gnat_util
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | \
	   ${SORT} -r | ${SED} -e '/lib\/gnat$$/d' -e 's/^/@dirrm /g' \
	   >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
