# New ports collection makefile for:	crafty-open-rock
# Date created:				28 December 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
# Based on ports by:			Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

PORTNAME=	crafty-open-rock
PORTVERSION=	19980707
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.uab.edu/pub/hyatt/common/rock/
DISTFILES=	rock.01 rock.02 rock.03 rock.04 rock.05 rock.06 rock.07 \
		rock.08 rock.09 rock.10

MAINTAINER=	mph@FreeBSD.org

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

DIST_SUBDIR=		crafty
NO_WRKSUBDIR=		yes
EXTRACT_ONLY=

do-build:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${CAT} ${DISTFILES} | ${GUNZIP_CMD}) | (cd ${WRKDIR}; crafty 3<&0 < ${FILESDIR}/book-building)

do-install:
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/book.bin ${PREFIX}/lib/crafty/rock-book.bin

.include <bsd.port.mk>
