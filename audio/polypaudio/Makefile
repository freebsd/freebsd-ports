# New ports collection makefile for:	polypaudio
# Date created:		29 October 2004
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	polypaudio
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/polypaudio/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

BUILD_DEPENDS=	lynx:${PORTSDIR}/www/lynx
LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_GNOME=	gnometarget gnomehack glib20
WANT_GNOME=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
# Needs libtool archive (.la) files for libltdl
USE_INC_LIBTOOL_VER=15
USE_LIBLTDL=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lm"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mglib12}!=""
USE_GNOME+=	glib12
PLIST_SUB+=	GLIB12=""
.else
PLIST_SUB+=	GLIB12="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/polyp/default.pa.in
	@${REINPLACE_CMD} -e 's|seq|jot|' \
		${WRKSRC}/polyp/esdcompat.sh.in
# 4.x doesn't have float_t
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|float_t|float|g' \
		${WRKSRC}/polyp/sample-util.c
.endif

post-install:
.for ii in default.pa daemon.conf client.conf
	${INSTALL_DATA} ${WRKSRC}/polyp/${ii} \
		${PREFIX}/etc/polypaudio/${ii}-dist
.endfor
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
