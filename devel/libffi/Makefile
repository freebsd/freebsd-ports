# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>
# $FreeBSD$

PORTNAME=	libffi
PORTVERSION=	3.0.13
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Foreign Function Interface

LICENSE=	MIT

TEST_DEPENDS=	runtest:${PORTSDIR}/misc/dejagnu

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Include tools for test suite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

INSTALL_TARGET=	install-strip
INFO=		libffi
PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-install:
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffi.h \
	    ${STAGEDIR}${PREFIX}/include/
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffitarget.h \
	    ${STAGEDIR}${PREFIX}/include/

regression-test: build
	@(cd ${WRKSRC} && ${MAKE_CMD} check)

.include <bsd.port.mk>
