# New ports collection makefile for:   xtide
# Date created:        30 August 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	xtide
PORTVERSION=	2.4
CATEGORIES=	astro
MASTER_SITES=	ftp://bel-marduk.unh.edu/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} harmonics.txt.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

IGNOREFILES=	harmonics.txt.gz

USE_XPM=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=	xtide.1 tide.1
MANCOMPRESSED=	no

post-extract:
	@${GZCAT} ${DISTDIR}/harmonics.txt.gz > ${WRKSRC}/harmonics

post-patch:
	@${PERL} -pi -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/TideContext.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tide ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/xtide.1 ${PREFIX}/man/man1/xtide.1
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/tide.1 ${PREFIX}/man/man1/tide.1
	@${MKDIR} ${PREFIX}/share/xtide
	${INSTALL_DATA} ${WRKSRC}/harmonics ${PREFIX}/share/xtide

.include <bsd.port.mk>
