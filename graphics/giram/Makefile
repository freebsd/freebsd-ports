# New ports collection makefile for:	giram
# Version required:    0.0.18
# Date created:        17 June 1999
# Whom:                Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

DISTNAME=	Giram-0.0.18
PKGNAME=	giram-0.0.18
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.minet.net/pub/giram/

MAINTAINER=	bfoz@glue.umd.edu

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray31

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

post-install:
	@${MKDIR} ${PREFIX}/Giram/SampleScenes
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/Giram/SampleScenes/

.include <bsd.port.mk>
