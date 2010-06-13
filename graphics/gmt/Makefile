# New ports collection makefile for:	gmt
# Date created:		10 May 2001
# Whom:			sec@42.org
#
# $FreeBSD$
#

PORTNAME=	gmt
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://falcon.grdl.noaa.gov/pub/gmt/ \
		ftp://ftp.iag.usp.br/pub/gmt/ \
		ftp://ftp.geologi.uio.no/pub/gmt/
DISTNAME=	GMT${PORTVERSION}
DISTFILES=	${EXTRACT_ONLY} ${EXTRACT_SUB}
DIST_SUBDIR=	gmt
EXTRACT_ONLY=	${DISTNAME}_progs${EXTRACT_SUFX} \
		${DISTNAME}_man${EXTRACT_SUFX}

MAINTAINER=	sec@42.org
COMMENT=	The Generic Mapping Tools data processing and display software package

LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf

EXTRACT_SUB=	GMT_share${EXTRACT_SUFX}

USE_BZIP2=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}/${PORTNAME} \
		--enable-wrapbin=${PREFIX}/bin \
		--enable-wrapman=${PREFIX}/man \
		--enable-shared
MAKE_ENV+=	NETCDFHOME=${LOCALBASE}
INSTALL_TARGET=	install install-data install-man install-wrapper

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

post-extract:
	@for file in ${EXTRACT_SUB}; do \
		if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

.ifdef(WITH_EVERYTHING)
WITH_COAST_HIGH=YES
WITH_COAST_FULL=YES
WITH_FAST_TRIANGLE=YES
WITH_SUPPL=YES
.endif

# High-rez coastlines (8M):
.ifdef(WITH_COAST_HIGH)
EXTRACT_SUB+=	GMT_high${EXTRACT_SUFX}
PLIST_SUB+=	COAST_HIGH=""
.else
PLIST_SUB+=	COAST_HIGH="@comment "
.endif

# Full-rez coastlines (28M):
.ifdef(WITH_COAST_FULL)
EXTRACT_SUB+=	GMT_full${EXTRACT_SUFX}
PLIST_SUB+=	COAST_FULL=""
.else
PLIST_SUB+=	COAST_FULL="@comment "
.endif

# Jonathan Shewchuck's Delauney triangulation routines (non-GPL)
.ifdef(WITH_FAST_TRIANGLE)
EXTRACT_SUB+=	triangle${EXTRACT_SUFX}
RESTRICTED=	No commercial use
RESTRICTED_FILES=	triangle${EXTRACT_SUFX}
CONFIGURE_ARGS+=	--enable-triangle
.endif

WITH_SUPPL?=	YES
# Supplemental programs which use GMT
.if defined(WITH_SUPPL) && ${WITH_SUPPL} != "NO"
EXTRACT_ONLY+=	${DISTNAME}_suppl${EXTRACT_SUFX}
INSTALL_TARGET+=	install-suppl
PLIST_SUB+=	SUPPL=""
post-configure:
	${TOUCH} ${WRKSRC}/src/mex/.skip
.else
PLIST_SUB+=	SUPPL="@comment "
.endif

MANL=		GMT.l

.include <bsd.port.post.mk>
