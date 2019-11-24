# Created by: Anders Andersson <anders@hack.org>
# $FreeBSD$

PORTNAME=	oregano
DISTVERSIONPREFIX=	v
DISTVERSION=	0.84.41-2
DISTVERSIONSUFFIX=	-gc4dc5f5
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schematic capture and circuit simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nroff:textproc/groff
LIB_DEPENDS=	libgoocanvas-2.0.so:graphics/goocanvas2

USES=		compiler:c11 desktop-file-utils gettext gnome pkgconfig \
		shared-mime-info waf
USE_GITHUB=	yes
GH_ACCOUNT=	drahnr
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 intltool libxml2 pango

GLIB_SCHEMAS=	io.ahoi.oregano.gschema.xml

INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} 's|$${MANDIR}|${MANPREFIX}/man|' ${WRKSRC}/data/wscript

post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/oregano bin/microtests

.include <bsd.port.mk>
