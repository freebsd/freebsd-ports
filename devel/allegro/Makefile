# New ports collection makefile for:	allegro
# Date created:		23-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	4.1.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	alleg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform library for games and multimedia programming

USE_XLIB=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -DHAVE_LIBPTHREAD" \
		LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-vga=no
MAKEFILE=	makefile
ALL_TARGET=	full-build
INSTALLS_SHLIB=	yes

SHLIB_VER=	41
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"
DEMO=		demo.c demo.dat demo.h music.txt ../readme.txt

INFO=		allegro

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
PKGNAMESUFFIX=	-esound
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=	--enable-esddigi=no
PLIST_SUB+=	ESOUND="@comment "
.endif

.if exists(${LOCALBASE}/lib/libartsc.so.0)
WITH_ARTS=	yes
.endif
.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS=""
.else
CONFIGURE_ARGS+=	--disable-artsdigi
PLIST_SUB+=	ARTS="@comment "
.endif

.if defined(WITHOUT_DEVEL)
INSTALL_TARGET=	mini-install install-man install-info
PLIST_SUB+=	FULL="@comment "
.else
INSTALL_TARGET=	full-install install-man install-info
PLIST_SUB+=	FULL=""
.endif

.if !defined(NOPORTDOCS)
PLIST_SUB+=	EXAMPLESDIR="share/examples/${PORTNAME}"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|${PORTVERSION}|${SHLIB_VER}|g' ${WRKSRC}/makefile.ver
	@${REINPLACE_CMD} -e 's|-l[$$]{lib_type}-[$$]{version}|-l\$${lib_type}|' \
		${WRKSRC}/misc/allegro-config.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.css  ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/demo/demo ${EXAMPLESDIR}
.for FILE in ${DEMO}
	${INSTALL_DATA} ${WRKSRC}/demo/${FILE} ${EXAMPLESDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.post.mk>
