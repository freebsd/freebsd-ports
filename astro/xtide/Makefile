# New ports collection makefile for:   xtide
# Date created:        30 August 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	xtide
PORTVERSION=	2.5
CATEGORIES=	astro
MASTER_SITES=	ftp://bel-marduk.unh.edu/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} harmonics.txt.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Harmonic tide clock and tide predictor

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

IGNOREFILES=	harmonics.txt.gz

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	xtide.1 tide.1

post-extract:
	@${GZCAT} ${DISTDIR}/harmonics.txt.gz > ${WRKSRC}/harmonics

post-patch:
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/TideContext.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tide ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/xtide.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/tide.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/harmonics ${DATADIR}

.include <bsd.port.mk>
