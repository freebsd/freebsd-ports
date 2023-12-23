PORTNAME=	oregano
DISTVERSIONPREFIX=	v
DISTVERSION=	0.84.43
PORTREVISION=	5
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schematic capture and circuit simulator
WWW=		https://ahoi.io/

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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${MANDIR}|${MANPREFIX}/man|' ${WRKSRC}/data/wscript

post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/oregano bin/microtests
	${RM} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/gschemas.compiled

.include <bsd.port.mk>
