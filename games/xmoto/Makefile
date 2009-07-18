# New ports collection makefile for:	xmoto
# Date created:		07 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	xmoto
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/xmoto/xmoto/${PORTVERSION}/ \
		http://mirror.amdmi3.ru/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Challenging 2D motocross platform game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		curl.5:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LUA=	5.1
USE_SQLITE=	3
USE_SDL=	sdl mixer ttf net
USE_GL=		gl glu
USE_DOS2UNIX=	src/*.cpp src/*.h
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog

OPTIONS=	ASIAN_TTF "Use asian TTF font" off

MAN6=		xmoto.6

.include <bsd.port.pre.mk>

.if defined(WITH_ASIAN_TTF)
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/TrueType/bkai00mp.ttf:${PORTSDIR}/chinese/arphicttf
CONFIGURE_ARGS+=--with-asian-ttf-file=${LOCALBASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf
.else
CONFIGURE_ARGS+=--without-asian-ttf-file
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV+=	LIBS="-lintl"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
