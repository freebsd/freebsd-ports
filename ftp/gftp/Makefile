# New ports collection makefile for:	gftp
# Date Created:		21 Feb 1999
# Whom:			Damjan Marion <dmarion@open.hr>
#
# $FreeBSD$
#

PORTNAME=	gftp
PORTVERSION=	2.0.16
PORTREVISION=	1
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

USE_GNOME+=	gnomehack
USE_REINPLACE=	yes

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--disable-gtkport --disable-gtk20
PKGNAMESUFFIX=	-nox11
LIB_DEPENDS+=	glib12.3:${PORTSDIR}/devel/glib12
.else
USE_X_PREFIX=	yes
WANT_GNOME=	yes
.if defined(WITH_GTK2)
RUN_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS+=	glib-2.0.200:${PORTSDIR}/devel/glib20 \
		gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20
CONFIGURE_ENV+=	_GTHREAD_LIBS="-lgthread-2.0"
.else
CONFIGURE_ARGS+=	--disable-gtk20
USE_GNOME+=	gtk12
CONFIGURE_ENV+=	_GTHREAD_LIBS="-lgthread12"
.endif
.endif

.include <bsd.port.pre.mk>

MAN1=		gftp.1

.if defined(WITHOUT_X11)
PLIST_SUB+=	NOX11:="@comment "
.else
PLIST_SUB+=	NOX11:=""
.endif

.if ${HAVE_GNOME:Mgnomelibs}!="" && !defined(WITH_GTK2)
USE_GNOME+=	gnomeprefix gnomelibs
PKGNAMESUFFIX+=	-gnome
PLIST_SUB+=	DATADIR="share/gnome"
MAKE_ENV=	HAVE_GNOME=1
.else
PLIST_SUB+=	DATADIR="share"
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITHOUT_X11=yes		Only build the text frontend."
	@${ECHO} "	WITH_GTK2=yes		Use gtk 2.x instead of 1.x"
	@${ECHO} ""

post-patch:
#	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
#		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
#		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
#		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|"-lssl |& -lcrypto|' ${WRKSRC}/configure

#	@${REINPLACE_CMD} -e 's|LDADD = |& @LIBINTL@ |g' \
#		${WRKSRC}/src/text/Makefile.in ${WRKSRC}/src/gtk/Makefile.in
.include <bsd.port.post.mk>
