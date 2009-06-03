# New ports collection makefile for:	nemiver
# Date created:		2008-02-22
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	nemiver
PORTVERSION=	0.6.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	romain@blogreen.org
COMMENT=	A C/C++ Debugger for GNOME

LIB_DEPENDS=	boost_unit_test_framework:${PORTSDIR}/devel/boost \
		gtop-2.0:${PORTSDIR}/devel/libgtop \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gtksourceviewmm-2:${PORTSDIR}/x11-toolkits/libgtksourceviewmm

OPTIONS=	GHEX "Enable memory view" off

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intltool gnomedocutils gconf2 vte
GCONF_SCHEMAS=	nemiver-workbench.schemas nemiver-dbgperspective.schemas
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
MAN1=		nemiver.1

CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 604100
BROKEN=		Does not compile on 6.x
.endif

.if defined(WITH_GHEX) && !defined(WITHOUT_GHEX)
CONFIGURE_ARGS+=--enable-memoryview
PLIST_SUB+=	GHEX=""
LIB_DEPENDS+=	gtkhex.0:${PORTSDIR}/editors/ghex
.else
CONFIGURE_ARGS+=--disable-memoryview
PLIST_SUB+=	GHEX="@comment "
.endif

.include <bsd.port.post.mk>
