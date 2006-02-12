# New ports collection makefile for:	vdrift
# Date created:		2005-11-09
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	vdrift
PORTVERSION=	20051103
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vdrift
DISTNAME=	${PORTNAME}-2005-11-03-src

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Open source driving simulation

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal

BROKEN=		Touches filesystem before 'make install'

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_SDL=	sdl image net
USE_REINPLACE=	yes

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
BROKEN=		"does not compile"
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-patch:
	@${FIND} ${WRKSRC}/src/* -type f -exec ${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' "{}" \;
	@${FIND} ${WRKSRC}/include/* -type f -exec ${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' "{}" \;
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|g' ${WRKSRC}/src/SConscript

do-build:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/vdrift ${PREFIX}/bin
	cd ${WRKSRC}/data && \
	${FIND} * -name SConscript -print0 | ${XARGS} -0 ${RM} && \
	${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in docs/AUTHORS docs/README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
