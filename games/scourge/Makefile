# New ports collection makefile for:	Scourge
# Date created:		2005-10-08
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	scourge
PORTVERSION=	0.16
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/.src/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	S.C.O.U.R.G.E. is a rogue-like game

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${DATADIR}/world/gui.txt:${PORTSDIR}/games/scourge-data

BROKEN=		Does not compile

USE_GL=		yes
USE_SDL=	sdl mixer net
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	DEBUG	"Produce an executable with debugging symbols"	off \
		EDITOR	"Install scourge editor"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Some dependencies do not compile on 4.x
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !defined(WITHOUT_EDITOR)
USE_WX=		2.6+
WX_COMPS=	wx contrib
WANT_UNICODE=	yes
PLIST_FILES+=	bin/${PORTNAME}-editor
HAVE_EDITOR=	true
.else
CONFIGURE_ARGS+=	--disable-editor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG:T} |g' ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
.if defined(HAVE_EDITOR)
	@${INSTALL_PROGRAM} ${WRKSRC}/src/tools/tools ${PREFIX}/bin/${PORTNAME}-editor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
