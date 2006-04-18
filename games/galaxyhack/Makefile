# New ports collection makefile for:	galaxyhack
# Date created:				10 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	galaxyhack
PORTVERSION=	1.62
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}-1.61-data${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	AI script based strategy game

LIB_DEPENDS=	boost_filesystem.3:${PORTSDIR}/devel/boost \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/src

USE_BZIP2=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_SDL=	gfx image mixer sdl

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

ALL_TARGET=	${PORTNAME}
SUB_FILES=	${PORTNAME}-sh
DATADIRS=	graphics fleets music gamedata standardpictures

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/settings.dat ${DATADIR}
.for d in ${DATADIRS}
	${CP} -R ${WRKDIR}/${PORTNAME}/${d} ${DATADIR}
.endfor

post-install:
# Fix permissions.
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD < 5.X
.endif

# Enable/disable compilation optimizations.
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=-O3
.endif

.include <bsd.port.post.mk>
