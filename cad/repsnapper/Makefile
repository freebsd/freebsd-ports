# Created by: Martin Dieringer <martin.dieringe@gmx.de>
# $FreeBSD$

PORTNAME=	repsnapper
DISTVERSION=	2.5a4
PORTREVISION=	2
CATEGORIES=	cad

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Controller and GCode generator for RepRap 3D printers

LICENSE=	GPLv2 BSD3CLAUSE MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libgtkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm \
		libzip.so:archivers/libzip
BUILD_DEPENDS+=	clang40:devel/llvm40

USE_GITHUB=	yes
GH_ACCOUNT=	timschmidt

USES=		compiler:c++11-lib autoreconf gmake libtool perl5 pkgconfig gettext
USE_GNOME=	gtkmm24 intltool libxml++26
USE_GL=		gl
USE_PERL5=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf.sample

.include <bsd.port.mk>
