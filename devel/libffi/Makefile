# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>
# $FreeBSD$

PORTNAME=	libffi
PORTVERSION=	3.0.11
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Foreign Function Interface

OPTIONS_DEFINE=	TEST
TEST_DESC=	Run regression test suite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
BUILD_DEPENDS+=	runtest:${PORTSDIR}/misc/dejagnu
.endif

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
USE_PKGCONFIG=	build
PLIST_SUB=	PORTVERSION=${PORTVERSION}

INFO=		libffi

MAN3=		ffi.3 ffi_call.3 ffi_prep_cif.3 ffi_prep_cif_var.3

.if ${PORT_OPTIONS:MTEST}
post-build:
	@cd ${WRKSRC} && ${MAKE} check
.endif

post-install:
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffi.h \
	    ${PREFIX}/include/
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffitarget.h \
	    ${PREFIX}/include/

.include <bsd.port.mk>
