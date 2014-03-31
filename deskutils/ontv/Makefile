# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/deskutils/ontv/Makefile,v 1.7 2007/07/23 21:02:59 mezz Exp $

PORTNAME=	ontv
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME Applet for monitoring current and upcoming TV programs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		tv_check:${PORTSDIR}/textproc/p5-xmltv

USE_BZIP2=	yes
USES=		gettext
USE_GNOME=	gnomehack gnomeprefix pygnomedesktop pygnomeextras pygtk2
USE_GMAKE=	yes
USE_PYTHON=	2
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
