# $FreeBSD$

PORTNAME=	wsjtx
PORTVERSION=	1.5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://physics.princeton.edu/pulsar/K1JT/:src \
		http://www.physics.princeton.edu/pulsar/K1JT/wsjtx-doc/:docs \
		LOCAL/db
DISTFILES=	wsjtx-1.5.0.tgz:src \
		wsjtx-main.html:docs

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook-xsl>0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libhamlib.so:${PORTSDIR}/comms/hamlib
RUN_DEPENDS=	${LOCALBASE}/bin/kvasd:${PORTSDIR}/comms/kvasd

MAKE_JOBS_UNSAFE=	yes
USE_QT5=	gui buildtools qmake_build widgets multimedia concurrent serialport
USE_GL=		yes
USE_GCC=	yes
USES=		cmake compiler:c++11-lib dos2unix fortran pkgconfig
#CMAKE_ARGS+=	 --debug-output --trace
CMAKE_ARGS+=	-DPORT_BUILDING::STRING="ON" \
		-DCMAKE_PREFIX_PATH+=${LOCALBASE}/wsjtx/lib

WRKSRC=		${WRKDIR}/wsjtx

do-extract:
		(cd ${WRKDIR};tar xvf ${DISTDIR}/wsjtx-1.5.0.tgz)
		(cd ${WRKDIR};tar xvf ${WRKDIR}/wsjtx-1.5.0/src/wsjtx.tgz)

post-install:
		${CP} ${DISTDIR}/wsjtx-main.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
