# New ports collection makefile for:	vdrift
# Date created:		2005-11-09
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	vdrift
PORTVERSION=	20060221
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-2006-02-21-src
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Open source driving simulation

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal
RUN_DEPENDS=	${X11BASE}/share/${PORTNAME}/settings/VDrift.config:${PORTSDIR}/games/vdrift-data

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_SDL=	sdl image net

MAKE_ENV=	CC="${CC}" CXX="${CXX}"
SCONS_ARGS=	prefix=${DATADIR} bin=${PREFIX}/bin

SUB_FILES=	pkg-message

OPTIONS=	DEBUG	"Additional debug information"	off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
SCONS_ARGS+=	release=0
.else
SCONS_ARGS+=	release=1
.endif

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${FIND} ${WRKSRC}/src/* -type f -exec ${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' "{}" \;
	@${FIND} ${WRKSRC}/include/* -type f -exec ${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' "{}" \;
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|g' ${WRKSRC}/src/SConscript

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/vdrift ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in docs/AUTHORS docs/README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
