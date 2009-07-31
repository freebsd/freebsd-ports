# New ports collection makefile for:	enigma
# Date created:				25 July 2002
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	enigma
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	enigma-game
DISTNAME=	${PORTNAME}-${PORTVERSION}-64bit

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Enigma is a reimplementation of Oxyd, a puzzle game

LIB_DEPENDS=	zipios.0:${PORTSDIR}/archivers/zipios++ \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2
BUILD_DEPENDS=	${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LUA=	5.1
LUA_COMPS=	lua toluaxx
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cxxlua \
		--with-libintl-prefix="${LOCALBASE}"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN6=		enigma.6

SUB_FILES=	pkg-message

PORTDOCS=	*

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/lib-src/lua ${WRKSRC}/lib-src/zipios++ \
		${WRKSRC}/lib-src/enet ${WRKSRC}/tools ${WRKSRC}/intl

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -E -e '/install-data-am/ s,install-(doc|index)DATA,,g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|=.*|=|' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
