# $FreeBSD$

PORTNAME=	electrix
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	SF/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Application to view PDF files

LICENSE=	GPLv2

USES=		pkgconfig desktop-file-utils
USE_BZIP2=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_PYTHON=	2

CONFIGURE_ARGS=	--prefix=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DBUS NLS PDF PS
OPTIONS_DEFAULT=	DBUS PDF

PDF_DESC=	Portable Document Format Support
PS_DESC=	PostScript Support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB=	NLS=""
USES+=		gettext
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
.else
CONFIGURE_ARGS+=	--disable-pdf
.endif

.if ${PORT_OPTIONS:MPS}
LIB_DEPENDS+=	libspectre.so:${PORTSDIR}/print/libspectre
.else
CONFIGURE_ARGS+=	--disable-ps
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} waf configure \
		${CONFIGURE_ARGS} && ${TRUE}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} waf build && ${TRUE}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} waf install && ${TRUE}

.include <bsd.port.mk>
