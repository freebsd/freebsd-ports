# New ports collection makefile for: eLectrix
# Date created:		2011-03-10
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	electrix
PORTVERSION=	0.2.0
CATEGORIES=	graphics print
MASTER_SITES=	SF/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	An application to view PDF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		poppler-glib.8:${PORTSDIR}/graphics/poppler-glib

USE_BZIP2=	yes
USE_GNOME=	gtk20 desktopfileutils intltool intlhack pkgconfig
USE_PYTHON=	yes
USE_GETTEXT=	yes

CFLAGS=	"-I${LOCALBASE}/include"
LFLAGS=	"-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--prefix=${PREFIX}

OPTIONS=	PS "Enable PostScript support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PS)
LIB_DEPENDS+=	spectre.1:${PORTSDIR}/print/libspectre
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

.include <bsd.port.post.mk>
