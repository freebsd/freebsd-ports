# Created by: Martin Dieringer <martin.dieringe@gmx.de>
# $FreeBSD$

PORTNAME=	repsnapper
DISTVERSION=	2.5a4
PORTREVISION=	5
CATEGORIES=	cad

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Controller and GCode generator for RepRap 3D printers

LICENSE=	GPLv2 BSD3CLAUSE MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libgtkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm \
		libpolyclipping.so:graphics/polyclipping \
		libzip.so:archivers/libzip

USES=		compiler:c++11-lib autoreconf gettext gmake libtool localbase \
		perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	timschmidt
USE_GNOME=	gtkmm24 intltool libxml++26
USE_GL=		gl
USE_PERL5=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

INSTALL_TARGET=	install-strip

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf.sample

.include <bsd.port.mk>
