PORTNAME=	libgnt
PORTVERSION=	2.14.3
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/pidgin/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Toolkit based on glib and ncurses for text-mode user interfaces
WWW=		https://keep.imfreedom.org/libgnt/libgnt/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libffi.so:devel/libffi

USES=		gettext-runtime gnome iconv:wchar_t meson pkgconfig tar:xz
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

MESON_ARGS=	-Dpython2=false

.include <bsd.port.mk>
