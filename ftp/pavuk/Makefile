# New ports collection makefile for:	pavuk
# Date created:				19 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	pavuk
PORTVERSION=	0.9.28
PORTREVISION=	3
CATEGORIES=	ftp www
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.idata.sk/~ondrej/sw/
MASTER_SITE_SUBDIR=	apps/www/mirroring
DISTNAME=	${PORTNAME}-0.9pl28
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP, FTP and Gopher mirroring tool

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_OPENSSL=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-locale-dir=${LOCALBASE}/share/locale \
		--disable-debug --disable-gnome --enable-threads

MAN1=		pavuk.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME=	gtk12
CONFIGURE_ARGS+=	--with-gtk-config="${GTK_CONFIG}"
.else
CONFIGURE_ARGS+=	--disable-gtk
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
.for f in AUTHORS BUGS CREDITS ChangeLog FAQ MAILINGLIST NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
