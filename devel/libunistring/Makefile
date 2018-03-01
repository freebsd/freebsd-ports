# $FreeBSD$

PORTNAME=	libunistring
PORTVERSION=	0.9.9
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	takefu@airport.fm
COMMENT=	Unicode string library

LICENSE=	GPLv2 LGPL3+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LIB
LICENSE_FILE_GFDL=	${WRKSRC}/doc/libunistring.texi

USES=		alias charsetfix gmake iconv libtool tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INFO=		${PORTNAME}

OPTIONS_DEFINE=	DOCS
CONFIGURE_ARGS=	--disable-static

.ifdef QEMU_EMULATING
# XXX bug 224740: configure hangs: GSlice: failed to allocate 496 bytes (alignment: 512)
CONFIGURE_ENV+=	gl_cv_func_printf_enomem=no
.endif

.include <bsd.port.mk>
