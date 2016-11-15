# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	xmoto
PORTVERSION=	0.5.11
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/xmoto/xmoto/${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Challenging 2D motocross platform game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libxdg-basedir.so:x11/libxdg-basedir
BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:devel/ode

GNU_CONFIGURE=	yes
USES=		compiler:features dos2unix gmake jpeg localbase lua:51 sqlite
USE_GNOME=	libxml2
USE_SDL=	sdl mixer ttf net
USE_GL=		gl glu
DOS2UNIX_GLOB=	*.cpp *.h

CPPFLAGS+=	-isystem${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog
PORTDATA=	*

DESKTOP_ENTRIES="XMoto" \
		"Motorcross game" \
		"${DATADIR}/xmoto_icone_x.ico" \
		"xmoto" \
		"Game;SportsGame;ArcadeGame;" \
		false

OPTIONS_DEFINE=	ASIAN_TTF DOCS NLS
OPTIONS_SUB=	yes

ASIAN_TTF_DESC=	Use asian TTF font

ASIAN_TTF_RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/bkai00mp.ttf:chinese/arphicttf
ASIAN_TTF_CONFIGURE_ON=	--with-asian-ttf-file=${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf
ASIAN_TTF_CONFIGURE_OFF=--without-asian-ttf-file

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
BROKEN=		does not build with gcc 4.2
.endif

post-extract:
	@${RM} -r ${WRKSRC}/src/ode

post-patch:
	@${REINPLACE_CMD} -e "s/lua5.1/lua-${LUA_VER}/g" ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
