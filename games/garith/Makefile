# New ports collection makefile for:	garith
# Version required:			2.1
# Date created:				5 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	garith-2.1
CATEGORIES=	games
MASTER_SITES=	http://www.cnm-vra.com/micah/garith/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

ALL_TARGET=	# empty
USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
WRKSRC=		${WRKDIR}/garith

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/garith ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/garith
.for file in BUGS COPYING HISTORY README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/garith
.endfor
.endif

.include <bsd.port.mk>
