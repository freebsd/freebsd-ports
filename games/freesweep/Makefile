# New ports collection makefile for:	freesweep
# Date created:				25 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	freesweep
PORTVERSION=	0.90
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.upl.cs.wisc.edu/~hartmann/sweep/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Minesweeper-style game for text-mode terminals

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-prefsdir=${DATADIR} \
		--with-scoresdir=${DATADIR}\
		--disable-debug-log
USE_GETOPT_LONG=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

ALL_TARGET=	# empty

MAN6=		freesweep.6

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
