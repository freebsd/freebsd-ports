# New ports collection makefile for:	replay
# Version required:		0.57
# Date created:			Oct 27 1998
# Whom:				Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/11/02 11:23:59 jseger Exp $
#

DISTNAME=	replay-source-dgtk_0.57a
PKGNAME=	replay-0.57a
CATEGORIES=	audio
MASTER_SITES=	http://replay.linuxpower.org/files/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		esd.0:${PORTSDIR}/audio/esound

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-esd
CONFIGURE_ENV=	LIBS="-L${PREFIX}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/replay ${PREFIX}/bin

.include <bsd.port.mk>
