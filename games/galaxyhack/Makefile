# New ports collection makefile for:	galaxyhack
# Date created:				10 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	galaxyhack
PORTVERSION=	1.55.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}-1.5-data${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	AI script based strategy game

LIB_DEPENDS=	boost_filesystem.3:${PORTSDIR}/devel/boost \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/src

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	gfx image mixer sdl
USE_REINPLACE=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

ALL_TARGET=	${PORTNAME}

SUB_FILES=	${PORTNAME}-sh

DATADIRS=	graphics fleets music gamedata standardpictures

post-extract:
# Remove CVS directories
	@${FIND} ${WRKDIR}/${PORTNAME} -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -rf

# Convert DOS text files to UNIX
	@${FIND} -E ${WRKSRC} -type f -iregex "(.*Makefile.*|.*\.(cpp|h))" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

do-install:
# Script
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${PREFIX}/bin/${PORTNAME}

# Program
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec

# Data
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/settings.dat ${DATADIR}
.for d in ${DATADIRS}
	@${CP} -R ${WRKDIR}/${PORTNAME}/${d} ${DATADIR}
.endfor

post-install:
# Fix permissions
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} < 500000
BROKEN=	"Does not compile on < 5.x"
.endif

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' \
				${WRKSRC}/${MAKEFILE}

# Enable/disable compilation optimizations
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>
