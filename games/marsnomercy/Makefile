# New ports collection makefile for:	Mars Land of No Mercy
# Date created:		2006-03-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	marsnomercy
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mars
DISTNAME=	mars-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A turn-based strategy game setting on Mars

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons

USE_GL=		gl
USE_SDL=	sdl image ttf
SCONS_ARGS=	prefix=${PREFIX}

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/mars-nomercy libexec/mars
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	mars-nomercy pkg-message
WRKSRC=		${WRKDIR}/mars-${PORTVERSION}

OPTIONS=	DEBUG	"With additional debug information"	off \
		OPENGL	"Install support for opengl"	off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
SCONS_ARGS+=	debug=1
.else
SCONS_ARGS+=	debug=0
.endif

.if defined(WITH_OPENGL)
SCONS_ARGS+=	with_opengl=1
.else
SCONS_ARGS+=	with_opengl=0
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}/data && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
		${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	@${INSTALL_SCRIPT} ${WRKDIR}/mars-nomercy ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mars ${PREFIX}/libexec/mars

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
