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

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libxdg-basedir.so:${PORTSDIR}/x11/libxdg-basedir
BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		dos2unix gmake jpeg lua:51
USE_GNOME=	libxml2
USE_SQLITE=	3
USE_SDL=	sdl mixer ttf net
USE_GL=		gl glu
DOS2UNIX_GLOB=	*.cpp *.h

CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog
PORTDATA=	*

OPTIONS_DEFINE=	ASIAN_TTF DOCS NLS
OPTIONS_SUB=	yes

ASIAN_TTF_DESC=	Use asian TTF font

ASIAN_TTF_RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/bkai00mp.ttf:${PORTSDIR}/chinese/arphicttf
ASIAN_TTF_CONFIGURE_ON=	--with-asian-ttf-file=${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf
ASIAN_TTF_CONFIGURE_OFF=--without-asian-ttf-file

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

DESKTOP_ENTRIES="XMoto" \
		"Motorcross game" \
		"${DATADIR}/xmoto_icone_x.ico" \
		"xmoto" \
		"Game;SportsGame;ArcadeGame;" \
		false

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		does not build
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/src/ode

post-patch:
	@${REINPLACE_CMD} -e "s/lua5.1/lua-${LUA_VER}/g" ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
