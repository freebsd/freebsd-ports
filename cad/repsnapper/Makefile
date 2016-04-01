# Created by: Martin Dieringer <martin.dieringe@gmx.de>
# $FreeBSD$

PORTNAME=	repsnapper
PORTVERSION=	2.3.2a3
PORTREVISION=	6
CATEGORIES=	cad
MASTER_SITES=	https://codeload.github.com/timschmidt/repsnapper/tar.gz/
DISTNAME=	${PORTVERSION}
EXTRACT_SUFX=	#
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Controller and GCode generator for RepRap 3D printers

LICENSE=	GPLv2 BSD3CLAUSE MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libgtkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm \
		libzip.so:archivers/libzip \

USES=		autoreconf gmake libtool perl5 pkgconfig
USE_GNOME=	gtkmm24 intltool libxml++26
USE_GL=		gl
USE_PERL5=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	install-strip

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/repsnapper/repsnapper.conf.sample

.include <bsd.port.mk>
