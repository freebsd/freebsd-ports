# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	vdrift
PORTVERSION=	20100630
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DATE_VERSION}
DISTNAME=	${PORTNAME}-${DATE_VERSION}-src
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open source driving simulation

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons \
		${LOCALBASE}/lib/libBulletCollision.a:${PORTSDIR}/devel/bullet \
		${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio
LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		boost_thread:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/settings/VDrift.config:${PORTSDIR}/games/vdrift-data

USE_BZIP2=	yes
USE_GL=		glew
USE_SDL=	sdl image net gfx

SCONS_ARGS=	prefix=${PREFIX} \
		datadir=share/${PORTNAME} \
		bindir=bin \
		use_binreloc=0
WRKSRC=		${WRKDIR}/${DISTNAME}

DATE_VERSION=	2010-06-30

SUB_FILES=	pkg-message

OPTIONS=	DEBUG	"Additional debug information"	off \
		NLS	"Internationalization support "	on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
SCONS_ARGS+=	release=0
.else
SCONS_ARGS+=	release=1
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
FLAG_NLS=	true
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,(__APPLE__),(__APPLE__) || defined(__FreeBSD__),g' \
		${WRKSRC}/include/quickmp.h
	@${REINPLACE_CMD} -e 's|GEN_clamped|btClamped|g' \
		${WRKSRC}/bullet/BulletDynamics/Dynamics/btRigidBody.cpp

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/vdrift ${PREFIX}/bin

.if defined(FLAG_NLS)
	@${MKDIR} ${DATADIR}/po
	@cd ${WRKSRC}/po && \
		${FIND} * -type f -name "*.po" -exec ${INSTALL_DATA} "{}" "${DATADIR}/po/{}" \;
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in docs/AUTHORS docs/README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
