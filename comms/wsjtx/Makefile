# $FreeBSD$

PORTNAME=	wsjtx
PORTVERSION=	1.6.0
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

LICENSE=	GPLv3

BUILD_DEPENDS=	a2x:textproc/asciidoc \
	 	${LOCALBASE}/share/xsl/docbook:textproc/docbook-xsl
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libxslt.so:textproc/libxslt
RUN_DEPENDS=	${LOCALBASE}/bin/kvasd:comms/kvasd

MAKE_JOBS_UNSAFE=	yes
USE_GL=		yes
USE_QT5=	gui buildtools qmake_build widgets multimedia concurrent serialport
USES=		cmake compiler:c++11-lib dos2unix fortran pkgconfig tar:tgz
CMAKE_ARGS+=	-DPORT_BUILDING::STRING="ON" \
		-DCMAKE_PREFIX_PATH+=${LOCALBASE}/wsjtx/lib
WRKSRC=		${WRKDIR}/${PORTNAME}

do-extract:
	${TAR} xf ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} -C${WRKDIR}
	${TAR} xf ${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/wsjtx.tgz -C${WRKDIR}

.include <bsd.port.mk>
