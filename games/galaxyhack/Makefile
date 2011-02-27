# New ports collection makefile for:	galaxyhack
# Date created:				10 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	galaxyhack
PORTVERSION=	1.74
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AI script based strategy game

LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_SDL=	gfx image mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}/src

OPTIONS=	FLEETS "Install additional fleets" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

ALL_TARGET=	${PORTNAME}
SUB_FILES=	${PORTNAME}-sh
FLEETS_FILE=	gh_fleets_020906.zip

.include <bsd.port.pre.mk>

.if defined(WITH_FLEETS)
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
DISTFILES+=	${FLEETS_FILE}
PLIST_SUB+=	FLEETS=""
.else
PLIST_SUB+=	FLEETS="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../settings.dat ${DATADIR}
.for d in fleets gamedata graphics music standardpictures
	${CP} -R ${WRKSRC}/../${d} ${DATADIR}
.endfor
.if defined(WITH_FLEETS)
	@${UNZIP_CMD} -o ${DISTDIR}/${FLEETS_FILE} -x "*/CVS/*" "*/.svn/*" \
		-d ${DATADIR}
.endif

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.post.mk>
