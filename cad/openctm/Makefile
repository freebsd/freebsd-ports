PORTNAME=	openctm
DISTVERSION=	1.0.3
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	https://sourceforge.net/projects/openctm/files/
DISTNAME=	OpenCTM-${DISTVERSION}-src

MAINTAINER=	db@FreeBSD.org
COMMENT=	File format for compression of 3D triangle meshes
WWW=		https://sourceforge.net/projects/openctm/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpnglite.so:graphics/pnglite \
		libtinyxml.so:textproc/tinyxml
BUILD_DEPENDS=	pnglite>0:graphics/pnglite \
		tinyxml>0:textproc/tinyxml

USES=		compiler:c++11-lang dos2unix gettext-runtime gl gmake gnome \
		jpeg pkgconfig tar:bz2
USE_GL=		gl glew glu glut
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
MAKEFILE=	Makefile.linux
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/OpenCTM-${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%STAGEDIR%%|${STAGEDIR}|' ${WRKSRC}/Makefile.linux
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/tools/Makefile.linux ${WRKSRC}/Makefile.linux

.include <bsd.port.mk>
