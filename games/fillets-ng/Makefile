# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	fillets-ng
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/fillets/Fish%20Fillets%20-%20Next%20Generation/${PORTVERSION}:source \
		SF/fillets/Fish%20Fillets%20-%20Next%20Generation/${DATAVERSION}:data
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:source \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A wonderful puzzle game

USE_SDL=	sdl mixer image ttf
USE_LUA=	5.1
USES=		gmake
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
CONFIGURE_ARGS=	--datadir="${DATADIR}" --with-lua="${LOCALBASE}"

PLIST_FILES=	bin/fillets man/man6/fillets.6.gz

PORTDOCS=	*
PORTDATA=	*

DATAVERSION=	1.0.0

ONLY_FOR_ARCHS=	i386 amd64

DESKTOP_ENTRIES="Fish Fillets - Next Generation" \
		"A wonderful puzzle game" \
		"${DATADIR}/images/icon.png" \
		"fillets" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS FRIBIDI
OPTIONS_DEFAULT=DOCS FRIBIDI

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=	libfribidi.so:${PORTSDIR}/converters/fribidi
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/ s|-llualib[50.]*||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^\(AM_CPPFLAGS.*(datadir)\)/.*|\1"\\"|' \
		${WRKSRC}/src/gengine/Makefile.in
.if ! ${PORT_OPTIONS:MFRIBIDI}
	@${REINPLACE_CMD} -e \
		's|FRIBIDI_CFLAGS=$$pkg_cv_FRIBIDI_CFLAGS||; s|FRIBIDI_LIBS=$$pkg_cv_FRIBIDI_LIBS||; s|have_fribidi="yes"|have_fribidi="no"|' \
		${WRKSRC}/configure
.endif

post-install:
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION} && \
		${COPYTREE_SHARE} "font	images music script sound" ${STAGEDIR}${DATADIR}/
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION}/doc && \
		${COPYTREE_SHARE} "*" ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
