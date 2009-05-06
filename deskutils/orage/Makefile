# New ports collection makefile for:	xfce4-calendar
# Date created:		2003-01-14
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	orage
PORTVERSION=	4.6.1
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A calendar application to manage your time with XFce 4

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui panel
USE_XORG=	xext xrender xinerama xi xrandr xcursor xcomposite xdamage x11 \
		xfixes

OPTIONS=	BDB	"Enable BDB support"		off \
		ICAL	"Enable libical support"	off

MAN1=		globaltime.1 orage.1

.include <bsd.port.pre.mk>

.if defined(WITH_BDB)
CONFIGURE_ARGS+=--with-bdb4=yes --with-bdb4_dir=${LOCALBASE}
USE_BDB=	40
.else
CONFIGURE_ARGS+=--with-bdb4=no
.endif

.if defined(WITH_ICAL)
LIB_DEPENDS+=	ical.43:${PORTSDIR}/devel/libical
.endif

post-patch:
.if !defined(WITH_ICAL)
	@${REINPLACE_CMD} -e 's|libical-|no-&|g' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
