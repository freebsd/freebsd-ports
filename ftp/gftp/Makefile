# New ports collection makefile for:	gftp
# Date Created:		21 Feb 1999
# Whom:			Damjan Marion <dmarion@open.hr>
#
# $FreeBSD$
#

PORTNAME=	gftp
PORTVERSION=	2.0.19
PORTREVISION=	4
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

WANT_GNOME=	yes

OPTIONS=	X11	"Build with X11 frontend"			on \
		NLS	"Native Language Support via gettext utilities"	on

.if !defined(WITHOUT_X11)
USE_XORG=	x11
.endif

.include <bsd.port.pre.mk>

USE_GNOME+=	gnomehack

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-gtkport
PKGNAMESUFFIX=	-nox11
USE_GNOME+=	glib20
PLIST_SUB+=	NOX11:="@comment "
.else
PLIST_SUB+=	NOX11:=""
WANT_GNOME=	yes
USE_GNOME+=	gtk20
CONFIGURE_ENV+=	_GTHREAD_LIBS="-lgthread-2.0"
.endif

MAN1=		gftp.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${HAVE_GNOME:Mgnomelibs}!="" && !defined(WITH_GTK2)
USE_GNOME+=	gnomeprefix gnomelibs
PKGNAMESUFFIX+=	-gnome
PLIST_SUB+=	MYGNOME=""
MAKE_ENV=	HAVE_GNOME=1
.else
PLIST_SUB+=	MYGNOME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|"-lssl |& -lcrypto|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|size_t dest_len|size_t *dest_len|g ; \
		s|\(gftp_filename_from_utf8 (gftp_request \* request,\) int force_local,|\1|' \
		${WRKSRC}/lib/charset-conv.c
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e 's|: install-pkgdataDATA|: |' \
		${WRKSRC}/docs/sample.gftp/Makefile.in
.endif

.include <bsd.port.post.mk>
