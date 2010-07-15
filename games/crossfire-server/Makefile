# New ports collection makefile for:	crossfire-server
# Date created:				Jan 30, 2002
# Whom:			Jasper Jongmans <j.jongmans@aprogas.net>
#
# $FreeBSD$
#

PORTNAME=	crossfire
PORTVERSION=	1.50.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-server/${PORTVERSION} \
		SF/${PORTNAME}/${PORTNAME}-maps/${PORTVERSION}:maps
PKGNAMESUFFIX=	-server
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${DISTNAME}.maps${EXTRACT_SUFX}:maps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for multiplayer graphical arcade and adventure game

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		png.6:${PORTSDIR}/graphics/png

USE_XORG=	ice sm x11 xaw xext xmu xpm xt
USE_SQLITE=	3
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-check=no

MAN6=		crossfire-config.6 crossfire-server.6 crossloop.6 \
		crossloop.web.6

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-extract:
	@${CHMOD} a+x ${WRKSRC}/utils/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl||g'
	@${REINPLACE_CMD} -e 's|^#.*/bin/sh|#! ${LOCALBASE}/bin/bash|g ; \
		 s|-ldl||g ; \
		 s|python[{].*[}]|${PYTHON_VERSION}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${DATADIR}/maps
	cd ${WRKDIR}/maps && ${COPYTREE_SHARE} . ${DATADIR}/maps
	@${CHOWN} ${BINOWN}:games ${PREFIX}/bin/crossfire-server
	@${CHMOD} 2755 ${PREFIX}/bin/crossfire-server
	@${CHGRP} -R games ${PREFIX}/var/crossfire

.include <bsd.port.mk>
