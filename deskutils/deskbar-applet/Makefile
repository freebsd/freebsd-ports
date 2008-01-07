# New ports collection makefile for:	deskbar-applet
# Date created:		2005-07-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/deskutils/deskbar-applet/Makefile,v 1.1 2007/11/30 22:05:58 marcus Exp $
#

PORTNAME=	deskbar-applet
PORTVERSION=	2.20.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Omnipresent versatile search interface

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GNOME=	gnomeprefix gnomehack pygnomedesktop intlhack
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	deskbar-applet.schemas

OPTIONS=	EVO "Enable evolution support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EVO)
USE_GNOME+=	evolutiondataserver
PLIST_SUB+=	EVO=""
.else
CONFIGURE_ARGS+=--disable-evolution
PLIST_SUB+=	EVO="@comment "
.endif

.if !defined(DISPLAY)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${LOCALBASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.if !defined(PACKAGE_BUILDING)
CONFIGURE_ENV+=	DISPLAY="localhost:1001"
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/deskbar/handlers/mozilla.py \
		${WRKSRC}/deskbar/core/Utils.py

.if !defined(DISPLAY)
pre-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
	@${LOCALBASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5

post-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
.endif

.include <bsd.port.post.mk>
