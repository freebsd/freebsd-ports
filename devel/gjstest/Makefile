# New ports collection makefile for:	gjstest
# Date created:		2011-10-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gjstest
PORTVERSION=	1.0.6
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight JS unit testing using the V8 engine

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	gflags:${PORTSDIR}/devel/gflags \
		glog:${PORTSDIR}/devel/glog \
		protobuf:${PORTSDIR}/devel/protobuf \
		re2:${PORTSDIR}/devel/re2 \
		v8:${PORTSDIR}/lang/v8 \
		xml2:${PORTSDIR}/textproc/libxml2

ALL_TARGET=	default
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
CXXFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes
USE_GMAKE=	yes

PROJECTHOST=	google-js-test

post-patch:
	@${REINPLACE_CMD} -e '/export PREFIX = / s|/usr/local|${PREFIX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CLOCK_PROCESS_CPUTIME_ID|CLOCK_PROF|' \
		${WRKSRC}/base/timer.cc
	@${REINPLACE_CMD} -e '1 s|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/gjstest/internal/cpp/generate_builtin_paths.sh \
		${WRKSRC}/scripts/*.sh

.include <bsd.port.mk>
