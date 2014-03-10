# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	opennurbs
PORTVERSION=	20121024
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://files.na.mcneel.com/opennurbs/5.0/2012-10-24/
MASTER_SITE_SUBDIR=${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Tools to accurately transfer 3-D geometry between applications

USES=		iconv:build dos2unix gmake zip
MAKE_ARGS=	CC=${CC} CCC=${CXX}

MAKEFILE=	makefile
EXAMPLESDIR=	${STAGEDIR}${PREFIX}/libexec/openNURBS

.include <bsd.port.pre.mk>

.if ${ARCH} != i386
MAKE_ARGS+=	ON_GNU_OPTIMIZER_FLAGS="-g -fPIC"
.endif

pre-build:
	${ICONV_CMD} -c -f utf-8 -t ascii ${WRKSRC}/opennurbs_version.h > ${WRKSRC}/opennurbs_version.h.tmp || ${TRUE}
	@${MV} ${WRKSRC}/opennurbs_version.h.tmp ${WRKSRC}/opennurbs_version.h

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libopenNURBS.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${EXAMPLESDIR}
.for i in brep read roundtrip userdata write
	@${INSTALL_PROGRAM} ${WRKSRC}/example_${i}/example_${i} ${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/openNURBS/zlib
	@${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/openNURBS/
	@${INSTALL_DATA} ${WRKSRC}/zlib/*.h ${STAGEDIR}${PREFIX}/include/openNURBS/zlib

.include <bsd.port.post.mk>
