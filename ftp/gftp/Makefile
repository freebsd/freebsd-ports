# New ports collection makefile for:	gftp
# Date Created:		21 Feb 1999
# Whom:			Damjan Marion <dmarion@open.hr>
#
# $FreeBSD$
#

PORTNAME=	gftp
PORTVERSION=	2.0.18
PORTREVISION=	0
CATEGORIES=	ftp
MASTER_SITES=	http://gftp.seul.org/ \
		ftp://gftp.seul.org/pub/gftp/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A free multithreaded GTK-based GUI ftp and sftp client

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--without-included-gettext
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

USE_REINPLACE=	yes
WANT_GNOME=	yes

OPTIONS=	X11 "Build with X11 frontend" on \
		GTK2 "gtk2 instead of gtk12" off

.if !defined(WITHOUT_X11)
USE_X_PREFIX=	yes
.endif

.include <bsd.port.pre.mk>

USE_GNOME+=	gnomehack

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-gtkport --disable-gtk20
PKGNAMESUFFIX=	-nox11
USE_GNOME+=	glib12
.else
WANT_GNOME=	yes
.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
CONFIGURE_ENV+=	_GTHREAD_LIBS="-lgthread-2.0"
.else
USE_GNOME+=	gtk12
CONFIGURE_ENV+=	_GTHREAD_LIBS="-lgthread12"
CONFIGURE_ARGS+=--disable-gtk20
.endif
.endif

MAN1=		gftp.1

.if defined(WITHOUT_X11)
PLIST_SUB+=	NOX11:="@comment "
.else
PLIST_SUB+=	NOX11:=""
.endif

.if ${HAVE_GNOME:Mgnomelibs}!="" && !defined(WITH_GTK2)
USE_GNOME+=	gnomeprefix gnomelibs
PKGNAMESUFFIX+=	-gnome
PLIST_SUB+=	DATADIR="share/gnome" MYGNOME=""
MAKE_ENV=	HAVE_GNOME=1
.else
PLIST_SUB+=	DATADIR="share" MYGNOME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|"-lssl |& -lcrypto|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
