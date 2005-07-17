# New ports collection makefile for:   xtide
# Date created:        30 August 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	xtide
PORTVERSION=	2.8.2
CATEGORIES=	astro
MASTER_SITES=	ftp://bel-marduk.unh.edu/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} harmonics-dwf-2005-06-05-v2.tcd.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Harmonic tide clock and tide predictor

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	extracxxflags="${CPPFLAGS}" extraldflags="${LDFLAGS}"

MAN1=		tide.1 xtide.1
MAN8=		xttpd.8
PLIST_FILES=	bin/tide bin/xtide bin/xttpd %%DATADIR%%/harmonics.tcd
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS=	`pkg-config --cflags-only-I libpng12` -I${LOCALBASE}/include
LDFLAGS=	`pkg-config --libs-only-L libpng12` -L${LOCALBASE}/lib

post-extract:
	@${GZCAT} ${DISTDIR}/harmonics-dwf-2005-06-05-v2.tcd.gz \
		> ${WRKSRC}/harmonics.tcd

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/TideContext.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tide ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xttpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/tide.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/xtide.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/xttpd.8 ${MAN8PREFIX}/man/man8
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/harmonics.tcd ${DATADIR}

.include <bsd.port.mk>
