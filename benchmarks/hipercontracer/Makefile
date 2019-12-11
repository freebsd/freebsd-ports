# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	hipercontracer
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.uni-due.de/~be0001/hipercontracer/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	High-Performance Connectivity Tracer (HiPerConTracer)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_log.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++14-lang python shebangfix tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man
SHEBANG_FILES=	src/addressinfogenerator src/get-default-ips src/tracedataimporter

.include <bsd.port.mk>
