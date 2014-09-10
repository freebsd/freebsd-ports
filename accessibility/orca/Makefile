# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/orca/Makefile,v 1.90 2010/11/16 12:00:48 avl Exp $

PORTNAME=	orca
PORTVERSION=	2.32.1
PORTREVISION=	3
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/pyatspi/__init__.py:${PORTSDIR}/accessibility/at-spi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
LIB_DEPENDS=	libgnome-mag.so:${PORTSDIR}/accessibility/gnome-mag
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/pyatspi/__init__.py:${PORTSDIR}/accessibility/at-spi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

USES=		gmake gettext pkgconfig tar:bzip2
USE_PYTHON=	2
USE_GNOME=	gnomeprefix libgnomeui gnomespeech pygnome2 \
		pygnomedesktop
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/orca/orca.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	${WRKSRC}/src/orca/orca_i18n.py

.include <bsd.port.mk>
