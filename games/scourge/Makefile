# New ports collection makefile for:	Scourge
# Date created:		2005-10-08
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	scourge
PORTVERSION=	0.13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scourge

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	S.C.O.U.R.G.E. is a rogue-like game

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_X_PREFIX=	yes
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

OPTIONS=	DEBUG	"Produce an executable with debugging symbols"	off

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
