PORTNAME=	xdg-user-dirs
DISTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://user-dirs.freedesktop.org/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tool to help manage personal user directories
WWW=		https://freedesktop.org/wiki/Software/xdg-user-dirs/

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gettext gmake gnome iconv localbase:ldflags
USE_GNOME=	libxslt:build
LDFLAGS+=	${ICONV_LIB}

.include <bsd.port.mk>
