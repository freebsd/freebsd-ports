# New ports collection makefile for:	Scourge
# Date created:		2005-10-08
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	scourge
PORTVERSION=	0.14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	S.C.O.U.R.G.E. is a rogue-like game

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${DATADIR}/world/gui.txt:${PORTSDIR}/games/scourge-data

USE_GL=		yes
USE_SDL=	sdl mixer net
USE_GMAKE=	yes
USE_GCC=	3.3+
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

PLIST_FILES=	bin/${PORTNAME}
WRKSRC=	${WRKDIR}/${PORTNAME}

OPTIONS=	DEBUG	"Produce an executable with debugging symbols"	off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.post.mk>
