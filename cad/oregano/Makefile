PORTNAME=	oregano
DISTVERSIONPREFIX=	v
DISTVERSION=	0.84.43
PORTREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	https://waf.io/:new_waf # for Python-3.11 compatibility
DISTFILES=	waf-2.1.1:new_waf
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}_GH0${EXTRACT_SUFX}

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
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 gtksourceview3 intltool libxml2 pango

GLIB_SCHEMAS=	io.ahoi.oregano.gschema.xml

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-extract: # use newer waf that is Python-3.11 compatible
	@${CP} ${DISTDIR}/waf-2.1.1 ${WRKSRC}/waf

post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/oregano bin/microtests
	${RM} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/gschemas.compiled

.include <bsd.port.mk>
