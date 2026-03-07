PORTNAME=	genius
DISTVERSION=	1.0.28
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME \
		http://ftp.5z.com/pub/genius/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment
WWW=		https://www.jirka.org/genius.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libharfbuzz.so:print/harfbuzz \
		libmpfr.so:math/mpfr

USES=		desktop-file-utils gettext-tools gmake gnome libtool perl5 \
		pkgconfig readline shared-mime-info tar:xz xorg
USE_GNOME=	intltool vte3
USE_PERL5=	test
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-extra-gcc-optimization \
		--disable-scrollkeeper \
		--disable-update-mimedb
INSTALL_TARGET=	install-strip

do-test:
	cd ${WRKSRC}/src; ${PERL} geniustest.pl

.include <bsd.port.mk>
