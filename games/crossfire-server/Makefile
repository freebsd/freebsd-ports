# New ports collection makefile for:	crossfire-server
# Date created:				Jan 30, 2002
# Whom:			Jasper Jongmans <j.jongmans@aprogas.net>
#
# $FreeBSD$
#

PORTNAME=	crossfire
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/
MASTER_SITE_SUBDIR=	crossfire
PKGNAMESUFFIX=	-server
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}.maps-big${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for multiplayer graphical arcade and adventure game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XPM=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib

MAN6=		crossfire.6 crossedit.6

post-patch:
	@${REINPLACE_CMD} -e 's|-ldes|-lcrypto|g' ${WRKSRC}/configure

post-install:
	@${TAR} -C ${WRKDIR} -cf - maps | ${TAR} -C ${DATADIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${CHOWN} ${BINOWN}:games ${PREFIX}/bin/crossfire
	@${CHMOD} 2755 ${PREFIX}/bin/crossfire
	@${CHGRP} -R games ${PREFIX}/var/crossfire

.include <bsd.port.mk>
