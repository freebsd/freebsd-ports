# New ports collection makefile for:	replay
# Version required:		0.61
# Date created:			Oct 27 1998
# Whom:				Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	replay-source-dgtk_0.61
PKGNAME=	replay-0.61
CATEGORIES=	audio
MASTER_SITES=	http://replay.linuxpower.org/files/ \
		ftp://ftp.replicant.nu/pub/replay/ \
		ftp://ftp.icemark.ch/pub/replay/ \
		ftp://k2.lund.se/pub/replay/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${PREFIX}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/replay ${PREFIX}/bin

.include <bsd.port.mk>
