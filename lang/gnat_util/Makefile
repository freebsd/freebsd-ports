# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnat_util
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	${UTIL_PR}
CATEGORIES=	lang
MASTER_SITES=	GCC/${MS_SUBDIR}
DISTNAME=	${IDENTIFICATION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Library used to build GNAT tools such as ASIS

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

USES=		ada tar:bzip2
NO_MTREE=	yes
DISTINFO_FILE=	${.CURDIR}/../${ADAXX}-aux/distinfo
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	MAKEOBJDIR=${WRKSRC}/obj

.include "${.CURDIR}/Makefile.sources"

.if defined(ADA_DEFAULT) && ${ADA_DEFAULT} == 49
.include "${.CURDIR}/../gcc-aux/Makefile.version"
.elif defined(ADA_DEFAULT) && ${ADA_DEFAULT} == 5
.include "${.CURDIR}/../gcc5-aux/Makefile.version"
.else
.include "${.CURDIR}/../gcc6-aux/Makefile.version"
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/obj
.for F in Makefile gnat_util.gpr sdefault_adb.gnat_util osint_scars.c
	@${CP} ${FILESDIR}/${F} ${WRKSRC}/
.endfor
.for F in ${GNAT_SRCS}
	@${CP} ${WRKDIR}/${DISTNAME}/gcc/ada/${F} ${WRKSRC}/
.endfor

post-install:
	# impunit is needed for GPS menus, just provide the source files
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/gcc/ada/impunit.* \
		${STAGEDIR}${PREFIX}/include/gnat_util
	# gnat_ugn.texi is used to generate gnat_switches.py for GPS
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/gcc/ada/gnat_ugn.texi \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
