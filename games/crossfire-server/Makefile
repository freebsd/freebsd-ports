# New ports collection makefile for:	crossfire-server
# Date created:				Jan 30, 2002
# Whom:			Jasper Jongmans <j.jongmans@aprogas.net>
#
# $FreeBSD$
#

PORTNAME=	crossfire
PORTVERSION=	1.9.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.real-time.com/pub/games/crossfire/
MASTER_SITE_SUBDIR=	crossfire
PKGNAMESUFFIX=	-server
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-1.maps${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for multiplayer graphical arcade and adventure game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XPM=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		crossedit.6 crossfire.6 crossfire-config.6 crossloop.6 \
		crossloop.web.6

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-install:
	@${MKDIR} ${DATADIR}/maps
	cd ${WRKDIR}/maps && ${FIND} . ! -name ".#*" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/maps
	@${CHOWN} ${BINOWN}:games ${PREFIX}/bin/crossfire
	@${CHMOD} 2755 ${PREFIX}/bin/crossfire
	@${CHGRP} -R games ${PREFIX}/var/crossfire

.include <bsd.port.mk>
