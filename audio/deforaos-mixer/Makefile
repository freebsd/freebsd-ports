# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mixer
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	http://www.defora.org/os/download/download/4456/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Mixer-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop audio mixer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils pkgconfig
USE_GNOME=	gtk20 cairo gdkpixbuf2

MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc po|data po|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|doc po src|doc src|' \
		${WRKSRC}/Makefile

post-patch:
	${REINPLACE_CMD} -e 's|Exec=mixer|Exec=${LOCALBASE}/bin/mixer|g' \
		${WRKSRC}/data/deforaos-mixer.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mixer

.include <bsd.port.mk>
