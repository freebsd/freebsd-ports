# New ports collection makefile for:	pavuk
# Date created:				19 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	pavuk
PORTVERSION=	0.9.35
PORTREVISION=	2
CATEGORIES=	ftp www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP, FTP and Gopher mirroring tool

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-locale-dir=${PREFIX}/share/locale \
		--disable-debug --disable-gnome --disable-js \
		--enable-utf-8 --enable-threads

MAN1=		pavuk.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if ${HAVE_GNOME:Mgtk20}!=""
PKGNAMESUFFIX=	-gtk
USE_GNOME+=	gtk20
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if defined(WITH_DANTE)
LIB_DEPENDS+=	socks.1:${PORTSDIR}/net/dante
CONFIGURE_ARGS+=	--with-socks-includes=${LOCALBASE}/include \
			--with-socks-libraries=${LOCALBASE}/lib
.elif defined(WITH_SOCKS5)
BUILD_DEPENDS+=${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--with-socks-includes=${LOCALBASE}/include \
			--with-socks-libraries=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-socks
.endif

pre-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread -DHAVE_MT|${PTHREAD_CFLAGS} -DHAVE_MT|g ; \
		 s|-pthread|${PTHREAD_LIBS}|g ; \
		 s|-lpthreads|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${FIND}  ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/icons|$$(pkgdatadir)/icons|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/pavuk_authinfo.sample ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/pavukrc.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS BUGS CREDITS ChangeLog COPYING MAILINGLIST NEWS \
	README TODO wget-pavuk.HOWTO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
