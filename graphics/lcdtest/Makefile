# New ports collection makefile for:	lcdtest
# Date created:			23 Mar 2007
# Whom:				Eric P. Scott <eps+pbug0703@ana.com>
#
# $FreeBSD$
#

PORTNAME=	lcdtest
PORTVERSION=	1.08
CATEGORIES=	graphics
MASTER_SITES=	http://www.brouhaha.com/~eric/software/lcdtest/download/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	LCD monitor test pattern generator

BUILD_DEPENDS=	pngtopnm:${PORTSDIR}/graphics/netpbm

USE_SDL=	sdl image

CFLAGS=		-I${LOCALBASE}/include
LINKFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

USE_SCONS=     yes
SCONS_ENV=     CFLAGS="${CFLAGS}" LINKFLAGS="${LINKFLAGS}" CC="${CC}"
SCONS_ARGS=    bindir=${PREFIX}/bin mandir=${PREFIX}/man/man1

PLIST_FILES=	bin/lcdtest
PORTDOCS=	README

MAN1=	lcdtest.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
