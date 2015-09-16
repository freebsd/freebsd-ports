# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD: head/deskutils/ontv/Makefile 339634 2014-01-13 21:00:02Z rene $
#   $MCom: ports/deskutils/ontv/Makefile,v 1.7 2007/07/23 21:02:59 mezz Exp $

PORTNAME=	ontv
PORTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Applet for monitoring current and upcoming TV programs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Uses unknown GNOME components pygnomedesktop and pygnomeextras
DEPRECATED=	Broken since update to gnome3
EXPIRATION_DATE=	2015-06-02

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		tv_check:${PORTSDIR}/textproc/p5-xmltv

USES=		gettext gmake pathfix python:2 tar:bzip2
USE_GNOME=	gnomeprefix pygnomedesktop pygnomeextras pygtk2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GCONF_SCHEMAS=	ontv.schemas
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/lib/python2.6|${PYTHON_LIBDIR}|' \
		${WRKSRC}/bin/ontv

post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/share/gnome-control-center/keybindings/90-ontv.xml

.include <bsd.port.mk>
