# New ports collection makefile for:	tkgeomap
# Date created:		25 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkgeomap
PORTVERSION=	2.10.1
CATEGORIES=	astro tk84
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Read, manipulate and display geo data

LIB_DEPENDS=	tclgeomap.0:${PORTSDIR}/astro/tclgeomap \
		tk${USE_TK}.1:${PORTSDIR}/x11-toolkits/tk${USE_TK}

CONFIGURE_ARGS=	--with-tclgeomap-include=${LOCALBASE}/include/tclgeomap --with-x
USE_TK=		yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PLIST_SUB=	INC=include/${PORTNAME} \
		LIB=lib/${PORTNAME}
MAKE_ENV=	MKLINKS_FLAGS=-s
USE_LDCONFIG=	yes

MANN=	igeomap.n tkgeomap.n tkgeomap_procs.n wdgeomap.n
MLINKS=	\
	wdgeomap.n latlontoxy.n \
	wdgeomap.n xytolatlon.n

post-install:
	@${LN} -sf ${PREFIX}/lib/libtkgeomap2.9.so ${PREFIX}/lib/libtkgeomap2.9.so.0
	@${LN} -sf ${PREFIX}/lib/libtkgeomap2.9.so ${PREFIX}/lib/libtkgeomap.so.0

post-patch:
	@${REINPLACE_CMD} -e 's/@PACKAGE@@VERSION@/@PACKAGE@/g' ${WRKSRC}/Makefile.in ${WRKSRC}/pkgIndex.tcl.in

# Maintainer section
MY_MLINKS:
	@cd ${MANNPREFIX}/man/mann/ && ls -l `${FIND} . -type l` | ${GREP} -E '(igeo|tkgeo|wdgeo)' | ${SED} -Ee 's#^.*\./(.*) -> (.*)$$#\2 \1 \\#' | ${SORT} -u

.include <bsd.port.mk>
