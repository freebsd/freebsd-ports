# New ports collection makefile for:	crossfire-server
# Date created:				Jan 30, 2002
# Whom:			Jasper Jongmans <j.jongmans@aprogas.net>
#
# $FreeBSD$
#

PORTNAME=	crossfire
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/
MASTER_SITE_SUBDIR=	crossfire
PKGNAMESUFFIX=	-server
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-${PORTVERSION}-maps.tar.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-includes="-I${LOCALBASE}/include -I${X11BASE}/include" \
		--with-ldflags="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		--without-x

MAN6=		crossfire.6 crossedit.6

post-extract:
	@${RM} ${WRKDIR}/maps/tmp

post-install:
	@${MKDIR} ${PREFIX}/share/crossfire
	@${CP} -R ${WRKDIR}/maps ${PREFIX}/share/crossfire
	@${MKDIR} ${PREFIX}/share/crossfire/maps/tmp
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/crossfire
	@${CHOWN} ${BINOWN}:games ${PREFIX}/bin/crossfire
	@${CHMOD} 2755 ${PREFIX}/bin/crossfire
	@${CHGRP} -R games ${PREFIX}/var/crossfire

.include <bsd.port.mk>
