# $FreeBSD$

PORTNAME=	wsjtx
PORTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt/${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		a2x:textproc/asciidoc \
		${LOCALBASE}/share/xsl/docbook:textproc/docbook-xsl
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libxslt.so:textproc/libxslt \
		libomp.so:devel/openmp

MAKE_JOBS_UNSAFE=	yes
USES=		cmake compiler:c++11-lib dos2unix fortran pkgconfig \
		qt:5 readline tar:tgz
USE_GL=		yes
USE_QT=		core gui buildtools network qmake_build widgets \
		multimedia concurrent printsupport serialport
CMAKE_ARGS+=	-DPORT_BUILDING::STRING="ON" \
		-DCMAKE_PREFIX_PATH+=${LOCALBASE}/wsjtx/lib \
		-DLOCALBASE::STRING="${LOCALBASE}"
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

BROKEN_i386=	does not build on i386 due to openmp

#
# This nonsense is because wsjtx is shipped with a copy of hamlib
# as well as wsjtx
#
.include <bsd.port.pre.mk>
do-extract:
# clogf is only present in FreeBSD 12
	${TAR} xf ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} -C${WRKDIR}
	${TAR} xf ${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/wsjtx.tgz -C${WRKDIR}
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000
	${CP}  ${FILESDIR}/clogf.c ${WRKDIR}/wsjtx
EXTRA_PATCHES=	${FILESDIR}/add_clogf
.endif

.include <bsd.port.post.mk>
