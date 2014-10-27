# $FreeBSD$

PORTNAME=	electrix
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	graphics print
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Application to view PDF files

LICENSE=	GPLv2

USES=		desktop-file-utils pkgconfig python:2 tar:bzip2
USE_GNOME=	gtk20 glib20 intltool intlhack

MAKE_ENV=	DESTDIR="${STAGEDIR}" \
		JOBS="${MAKE_JOBS_NUMBER}" \
		LINKFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=		DBUS NLS PDF PS
OPTIONS_DEFAULT=	DBUS PDF
OPTIONS_SUB=		yes

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
DBUS_CONFIGURE_OFF=	--disable-dbus

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

PDF_LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
PDF_CONFIGURE_OFF=	--disable-pdf

PS_LIB_DEPENDS=		libspectre.so:${PORTSDIR}/print/libspectre
PS_CONFIGURE_OFF=	--disable-ps

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} waf configure \
		${CONFIGURE_ARGS} && ${TRUE})

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} waf build && ${TRUE})

do-install:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} waf install && ${TRUE})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/electrix

.include <bsd.port.mk>
