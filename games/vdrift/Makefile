# New ports collection makefile for:	vdrift
# Date created:		2005-11-09
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	vdrift
PORTVERSION=	20070323
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-2007-03-23-src
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open source driving simulation

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/settings/VDrift.config:${PORTSDIR}/games/vdrift-data

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	sdl image net gfx

MAKE_ENV=	CC="${CC}" CXX="${CXX}"
SCONS_ARGS=	prefix=${PREFIX} \
		datadir=share/${PORTNAME} \
		bindir=bin \
		use_binreloc=0
WRKSRC=		${WRKDIR}/build/${DISTNAME}

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
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e "s|'openal'|'openal','alut'|g" ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|^os.system.*||g' ${WRKSRC}/src/SConscript

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/vdrift ${PREFIX}/bin

.if defined(FLAG_NLS)
.	for DIRE in nl
		@cd ${WRKSRC}/po/share/locale/${DIRE}/LC_MESSAGES && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" ${PREFIX}/share/locale/${DIRE}/LC_MESSAGES \;
.	endfor
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
