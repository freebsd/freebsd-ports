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
NO_MTREE=	yes
DISTINFO_FILE=	${.CURDIR}/../gcc-aux/distinfo
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	MAKEOBJDIR=${WRKSRC}/obj

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
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | \
	   ${SORT} -r | ${SED} -e '/lib\/gnat$$/d' -e 's/^/@dirrm /g' \
	   >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>

