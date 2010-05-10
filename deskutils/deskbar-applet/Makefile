# New ports collection makefile for:	deskbar-applet
# Date created:		2005-07-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/deskbar-applet/Makefile,v 1.114 2010/05/02 11:44:22 kwm Exp $
#

PORTNAME=	deskbar-applet
PORTVERSION=	2.30.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Omnipresent versatile search interface

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack pygnomedesktop intlhack
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_DISPLAY=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	deskbar-applet.schemas

OPTIONS=	EVO "Enable evolution support" on

.include <bsd.port.pre.mk>

_OSRELEASE!=	${UNAME} -r

.if !defined(WITHOUT_EVO)
USE_GNOME+=	evolutiondataserver
PLIST_SUB+=	EVO=""
.else
CONFIGURE_ARGS+=--disable-evolution
PLIST_SUB+=	EVO="@comment "
.endif

.if ${PYTHON_REL} < 250
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/deskbar/handlers/mozilla.py \
		${WRKSRC}/deskbar/core/Utils.py

.include <bsd.port.post.mk>
