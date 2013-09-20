# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>
# $FreeBSD$

PORTNAME=	libffi
PORTVERSION=	3.0.13
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Foreign Function Interface

TEST_DEPENDS=	runtest:${PORTSDIR}/misc/dejagnu

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Include tools for test suite

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	pathfix pkgconfig
PLIST_SUB=	PORTVERSION=${PORTVERSION}

INFO=		libffi

MAN3=		ffi.3 ffi_call.3 ffi_prep_cif.3 ffi_prep_cif_var.3

post-install:
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffi.h \
	    ${PREFIX}/include/
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffitarget.h \
	    ${PREFIX}/include/

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
