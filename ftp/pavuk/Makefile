# New ports collection makefile for:	pavuk
# Date created:				19 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	pavuk
PORTVERSION=	0.9.27
CATEGORIES=	ftp www
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.idata.sk/~ondrej/sw/
MASTER_SITE_SUBDIR=	apps/www/mirroring
DISTNAME=	${PORTNAME}-0.9pl27
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

WANT_GTK=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--include-deps
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS= --with-locale-dir=${LOCALBASE}/share/locale \
		--disable-debug --disable-gnome --enable-threads

MAN1=		pavuk.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
CONFIGURE_ARGS+=	--with-gtk-config="${GTK_CONFIG}"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if defined(WITH_SSL)
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

pre-configure:
	@cd ${WRKSRC} && aclocal

post-install:
	${INSTALL_DATA} ${WRKSRC}/pavuk_authinfo.sample ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/pavukrc.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pavuk
.for file in AUTHORS BUGS CREDITS ChangeLog FAQ MAILINGLIST NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/pavuk
.endfor
.endif

.include <bsd.port.post.mk>
