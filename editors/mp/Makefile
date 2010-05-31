# New ports collection makefile for:	mp
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mp
PORTVERSION=	3.3.18b
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://triptico.com/download/

MAINTAINER=	az@FreeBSD.org
COMMENT=	A programming text editor

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config.sh
CONFIGURE_ARGS=	--prefix=${PREFIX} --without-win32

OPTIONS=	CURSES	"Build with ncurses support"	on \
		NLS	"Native language support"	on \
		GTK1	"Build with GTK1 support"	off \
		GTK2	"Build with GTK2 support"	off \
		PCRE	"Build with PCRE support"	on

MAN1=	mp.1

.include <bsd.port.pre.mk>

.if !defined(WITH_CURSES)
CONFIGURE_ARGS+=	--without-curses
.endif

.if defined(WITH_GTK1) || defined(WITH_GTK2)
.include "${PORTSDIR}/Mk/bsd.gnome.mk"
.if defined(WITH_GTK1) && !defined(WITH_GTK2)
USE_GNOME+=	gtk12
.else
CONFIGURE_ARGS+=	--without-gtk1
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--without-gettext
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/makefile.in

.include <bsd.port.post.mk>
