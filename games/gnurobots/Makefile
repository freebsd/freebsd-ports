# New ports collection makefile for:	gnurobots
# Date created:				22 Sept 2000
# Whom:					Aaron VonderHaar <avh4@usa.net>
#
# $FreeBSD$
#

PORTNAME=	gnurobots
PORTVERSION=	1.0D
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnurobots

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diversion wherein Scheme-coded robots explore a world

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
USE_XPM=	yes
USE_XLIB=	yes

pre-patch:
	${CP} ${WRKSRC}/getopt/getopt.h ${WRKSRC}/include
	${CP} ${WRKSRC}/getopt/getopt.c ${WRKSRC}/src
	${CP} ${WRKSRC}/getopt/getopt1.c ${WRKSRC}/src

do-install:
	${MKDIR} ${PREFIX}/share/gnurobots/maps ${PREFIX}/share/gnurobots/scheme \
		${PREFIX}/share/doc/gnurobots
	${INSTALL_PROGRAM} ${WRKSRC}/src/robots ${PREFIX}/bin/gnurobots
	${INSTALL_PROGRAM} ${WRKSRC}/src/robots_logfile ${PREFIX}/bin/gnurobots_logfile
	${INSTALL_PROGRAM} ${WRKSRC}/src/xrobots ${PREFIX}/bin/xgnurobots
	${INSTALL_DATA} ${WRKSRC}/maps/* ${PREFIX}/share/gnurobots/maps/
	${INSTALL_DATA} ${WRKSRC}/scheme/* ${PREFIX}/share/gnurobots/scheme/
	${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/gnurobots/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
