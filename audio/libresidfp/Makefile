PORTNAME=	libresidfp
DISTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/libsidplayfp/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reverse engineered software emulation of MOS6581/8580 SID chip
WWW=		https://github.com/libsidplayfp/libresidfp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++23-lang libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ENV=	ac_cv_prog_HAVE_DOXYGEN=false
CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
