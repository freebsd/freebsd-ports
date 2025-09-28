PORTNAME=	xdg-user-dirs
DISTVERSION=	0.19
CATEGORIES=	devel
MASTER_SITES=	https://user-dirs.freedesktop.org/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Tool to help manage personal user directories
WWW=		https://freedesktop.org/wiki/Software/xdg-user-dirs/

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl

USES=		gettext gnome iconv localbase:ldflags meson tar:xz
USE_GNOME=	libxslt:build
LDFLAGS+=	${ICONV_LIB}

.include <bsd.port.mk>
