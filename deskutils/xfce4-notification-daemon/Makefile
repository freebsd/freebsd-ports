# New ports collection makefile for:	notification-daemon
# Date created:				16 Nov 2007
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	notification-daemon
PORTVERSION=	0.3.7
PORTREVISION=	4
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/notification-daemon-xfce/ \
		CRITICAL
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PORTNAME}-xfce-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Port of Gnome's notification-daemon for the Xfce desktop

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	sexy.2:${PORTSDIR}/x11-toolkits/libsexy \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil libgui
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/xfce4 \
			--libexecdir=${PREFIX}/libexec/xfce4 \
			--with-dbus-services=${PREFIX}/share/dbus-1/services

CONFLICTS=	notification-daemon-[0-9]*

OPTIONS=	GRADIENT "Show a gradient look in the default theme"  off \
		CLOSE    "Show the close button in the default theme" on  \
		NLS      "Enable Native Language Support"             on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_GRADIENT)
CONFIGURE_ARGS+=	--enable-gradient-look
.endif

.if defined(WITHOUT_CLOSE)
CONFIGURE_ARGS+=	--disable-close-button
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(notification-daemon-xfce\)-1.0|\1|' \
		${WRKSRC}/src/daemon/Makefile.am \
		${WRKSRC}/src/daemon/Makefile.in \
		${WRKSRC}/src/themes/bubble/Makefile.am \
		${WRKSRC}/src/themes/bubble/Makefile.in \
		${WRKSRC}/src/themes/standard/Makefile.am \
		${WRKSRC}/src/themes/standard/Makefile.in
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's|\(USE_NLS=\)yes|\1no|' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
