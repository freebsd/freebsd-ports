# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/liboobs/Makefile,v 1.50 2010/09/27 17:46:12 kwm Exp $

PORTNAME=	liboobs
PORTVERSION=	2.32.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Wrapping library to the System Tools Backends

BUILD_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/org.freedesktop.SystemToolsBackends.conf:${PORTSDIR}/sysutils/system-tools-backends
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
    		libhal.so:${PORTSDIR}/sysutils/hal
RUN_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/org.freedesktop.SystemToolsBackends.conf:${PORTSDIR}/sysutils/system-tools-backends

USES=		gmake libtool:keepla pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc --with-hal
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

# disable utmpx detection on early 9.x and below.
# We still have only utmp there
post-patch:
.if ${OSVERSION} < 900007
	@${REINPLACE_CMD} -e 's|utmpx|utmp|g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
