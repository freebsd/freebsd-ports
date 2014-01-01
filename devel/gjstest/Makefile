# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gjstest
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}-${PORTVERSION}.${SNAPSHOT}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight JS unit testing using the V8 engine

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libgflags.so:${PORTSDIR}/devel/gflags \
		libglog.so:${PORTSDIR}/devel/glog \
		libprotobuf.so:${PORTSDIR}/devel/protobuf \
		libre2.so:${PORTSDIR}/devel/re2 \
		libv8.so:${PORTSDIR}/lang/v8 \
		libxml2.so:${PORTSDIR}/textproc/libxml2

ALL_TARGET=	default
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
CXXFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes
USES=		gmake

PROJECTHOST=	google-js-test
SNAPSHOT=	20130304

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(Get\)\(PointerFromInternalField\)|\1Aligned\2|' \
		-e 's|\(Set\)\(PointerInInternalField\)|\1Aligned\2|' \
		${WRKSRC}/gjstest/internal/cpp/typed_arrays.cc
	@${REINPLACE_CMD} -e '/export PREFIX = / s|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CLOCK_PROCESS_CPUTIME_ID|CLOCK_PROF|' ${WRKSRC}/base/timer.cc
	@${REINPLACE_CMD} -e '1 s|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/gjstest/internal/cpp/generate_builtin_paths.sh ${WRKSRC}/scripts/*.sh
	@${REINPLACE_CMD} -e 's|^g++ |${CXX} |' ${WRKSRC}/scripts/cc_binary_build.sh

.include <bsd.port.mk>
