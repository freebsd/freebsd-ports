# New ports collection makefile for:	liboobs
# Date created:		2006-06-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/liboobs/Makefile,v 1.46 2010/04/01 22:27:34 kwm Exp $
#

PORTNAME=	liboobs
PORTVERSION=	2.30.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Wrapping library to the System Tools Backends

BUILD_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/org.freedesktop.SystemToolsBackends.conf:${PORTSDIR}/sysutils/system-tools-backends
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
    		hal.1:${PORTSDIR}/sysutils/hal
RUN_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/org.freedesktop.SystemToolsBackends.conf:${PORTSDIR}/sysutils/system-tools-backends

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc --with-hal
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

.include <bsd.port.pre.mk>

# disable utmpx detection on early 9.x and below.
# We still have only utmp there
post-patch:
.if ${OSVERSION} < 900007
	@${REINPLACE_CMD} -e 's|utmpx|utmp|g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
