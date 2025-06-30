PORTNAME=	repsnapper
DISTVERSION=	2.5a5
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Controller and GCode generator for RepRap 3D printers
WWW=		https://reprap.org/wiki/RepSnapper_Manual:Introduction

LICENSE=		BSD3CLAUSE GPLv2 MIT
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2=	${WRKSRC}/licenses/GPL-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/licenses/MIT.txt

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libgtkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm \
		libpolyclipping.so:graphics/polyclipping \
		libzip.so:archivers/libzip

USES=		autoreconf compiler:c++11-lib gettext gl gmake gnome libtool \
		localbase perl5 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	timschmidt
USE_GL=		gl glu
USE_GNOME=	gtkmm24 intltool libxml++26 pangox-compat
USE_PERL5=	build
USE_XORG=	x11

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf.sample

.include <bsd.port.mk>
