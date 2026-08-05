PORTNAME=	invada-studio-plugins
DISTVERSIONPREFIX=	lv2_
DISTVERSION=	1.2.0
DISTVERSIONSUFFIX=	-nopkg
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://launchpad.net/invada-studio/lv2/1.2/+download/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 audio effect plugins, ported from VST
WWW=		https://launchpad.net/invada-studio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake gnome localbase pkgconfig tar:tgz
USE_GNOME=	cairo gdkpixbuf glib20 gtk20
LLD_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

# attempt to fix build error on aarch64: /usr/local/bin/ld: unrecognized option '-Wl,--fix-cortex-a53-843419'
# it's not clear where does this option come from (is it set in /etc/make.conf ?)
LDFLAGS_aarch64=	-Wl,--no-fix-cortex-a53-843419

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/*/*.so

.include <bsd.port.mk>
