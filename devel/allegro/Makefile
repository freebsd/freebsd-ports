# New ports collection makefile for:	allegro
# Date created:		23-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	4.0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	alleg

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -DHAVE_LIBPTHREAD" \
		LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-vga=no
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

SHLIB_VER=	4
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
PKGNAMESUFFIX=	-esound
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=	--enable-esddigi=no
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITHOUT_DEVEL)
INSTALL_TARGET=	mini-install install-man install-info
PLIST_SUB+=	FULL="@comment "
.else
INSTALL_TARGET=	full-install install-man install-info
PLIST_SUB+=	FULL=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|${PORTVERSION}|${SHLIB_VER}|g' ${WRKSRC}/makefile.ver
	@${REINPLACE_CMD} -e 's|-l[$$]{lib_type}-[$$]{version}|-l\$${lib_type}|' \
		${WRKSRC}/misc/allegro-config.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${DOCSDIR}
.endif

.include "Makefile.man"
.include <bsd.port.post.mk>
