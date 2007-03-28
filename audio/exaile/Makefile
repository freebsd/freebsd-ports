# New ports collection makefile for:	exaile
# Date created:		19 December 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exaile
DISTVERSION=	0.2.9
CATEGORIES=	audio
MASTER_SITES=	http://www.exaile.org/files/ GENTOO/distfiles
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	AmaroK replacement for GTK+

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_SITELIBDIR}/gtk-2.0/sexy.so:${PORTSDIR}/x11-toolkits/py-sexy \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23

USE_GETTEXT=	yes
USE_GNOME=	pygtk2 pygnomeextras
USE_GSTREAMER=	python
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^PREFIX/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^PYTHON_DIR/s|=.*|=${PYTHON_INCLUDEDIR}|' ${WRKSRC}/mmkeys/Makefile

.include <bsd.port.mk>
