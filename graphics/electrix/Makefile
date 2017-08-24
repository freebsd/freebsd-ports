# $FreeBSD$

PORTNAME=	electrix
PORTVERSION=	0.2.0
PORTREVISION=	10
CATEGORIES=	graphics print
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application to view PDF files

LICENSE=	GPLv2

USES=		desktop-file-utils pkgconfig python:2 tar:bzip2 waf
USE_GNOME=	gtk20 glib20 intltool intlhack

MAKE_ENV=	DESTDIR="${STAGEDIR}" \
		JOBS="${MAKE_JOBS_NUMBER}" \
		LINKFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=		DBUS NLS PDF PS
OPTIONS_DEFAULT=	DBUS PDF
OPTIONS_SUB=		yes

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_OFF=	--disable-dbus

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_CONFIGURE_OFF=	--disable-pdf

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_CONFIGURE_OFF=	--disable-ps

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/electrix

.include <bsd.port.mk>
