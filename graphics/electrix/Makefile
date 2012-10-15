# $FreeBSD$
#

PORTNAME=	electrix
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	SF/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	An application to view PDF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		poppler-glib:${PORTSDIR}/graphics/poppler-glib

USE_BZIP2=	yes
USE_GNOME=	gtk20 desktopfileutils intltool intlhack
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_PKGCONFIG=	build


CONFIGURE_ARGS=	--prefix=${PREFIX}

OPTIONS_DEFINE=	PS

PS_DESC=	PostScript support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPS}
LIB_DEPENDS+=	spectre:${PORTSDIR}/print/libspectre
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

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
