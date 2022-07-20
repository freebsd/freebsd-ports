PORTNAME=	libgsf
PORTVERSION=	1.14.49
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Extensible I/O abstraction for dealing with structured file formats

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

USES=		cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	gdkpixbuf2 intlhack introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection
CPE_VENDOR=	gnome

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
