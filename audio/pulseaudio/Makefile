# New ports collection makefile for:	polypaudio
# Date created:		29 October 2004
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/audio/pulseaudio/Makefile,v 1.5 2006/09/10 00:51:05 mezz Exp $
#

PORTNAME=	pulseaudio
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		oil-0.3.1:${PORTSDIR}/devel/liboil

CONFLICTS=	polypaudio-[1-9]*

USE_GNOME=	gnometarget gnomehack glib20
WANT_GNOME=	yes
USE_XLIB=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libltdl:15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lm"

CONFIGURE_ARGS+=	--disable-lirc # untested

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.X
.endif

.if (exists(${LOCALBASE}/lib/libavahi-core.a) || defined(PACKAGE_BUILDING) \
	|| defined(WITH_AVAHI)) && !defined(WITHOUT_AVAHI)
LIB_DEPENDS+=	avahi-core.5:${PORTSDIR}/net/avahi
CONFIGURE_ARGS+=	--enable-avahi
PLIST_SUB+=	AVAHI=""
.else
CONFIGURE_ARGS+=	--disable-avahi
PLIST_SUB+=	AVAHI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/daemon/default.pa.in

post-install:
.for ii in default.pa daemon.conf client.conf
	${INSTALL_DATA} ${WRKSRC}/src/${ii} \
		${PREFIX}/etc/pulse/${ii}-dist
.endfor
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
