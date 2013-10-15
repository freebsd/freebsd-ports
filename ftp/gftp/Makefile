# Created by: Damjan Marion <dmarion@open.hr>
# $FreeBSD$

PORTNAME=	gftp
PORTVERSION=	2.0.19
PORTREVISION=	5
CATEGORIES=	ftp
MASTER_SITES=	http://gftp.seul.org/ \
		ftp://gftp.seul.org/pub/gftp/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A free multithreaded GTK-based GUI ftp and sftp client

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--without-included-gettext
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

WANT_GNOME=	yes

BROKEN=		Dumps core when connecting to a host with pthread_mutex_lock: Operation not permitted

OPTIONS_DEFINE=	X11 NLS
OPTIONS_DEFAULT=	X11

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
.endif

USES=	pathfix

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	NOX11:=""
WANT_GNOME=	yes
USE_GNOME+=	gtk20
CONFIGURE_ENV+=	_GTHREAD_LIBS="-lgthread-2.0"
.else
CONFIGURE_ARGS+=--disable-gtkport
USE_GNOME+=	glib20
PLIST_SUB+=	NOX11:="@comment "
.endif

MAN1=		gftp.1

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|"-lssl |& -lcrypto|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|size_t dest_len|size_t *dest_len|g ; \
		s|\(gftp_filename_from_utf8 (gftp_request \* request,\) int force_local,|\1|' \
		${WRKSRC}/lib/charset-conv.c
.if ! ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e 's|: install-pkgdataDATA|: |' \
		${WRKSRC}/docs/sample.gftp/Makefile.in
.endif

.include <bsd.port.post.mk>
