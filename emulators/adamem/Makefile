# New ports collection makefile for:   	adamem
# Date created:				November 11, 2001
# Whom:					Jeremy Karlson
#
# $FreeBSD$
#

PORTNAME=	adamem
PORTVERSION=	1.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/~dekogel/files/coleco/
DISTNAME=	${PORTNAME}

MAINTAINER=	karlj000@unbc.ca

BROKEN=		"Does not compile"

USE_XLIB=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	x

WRKSRC=		${WRKDIR}

PROGDIR=	${PREFIX}/${PORTNAME}
DOCDIR=		${PREFIX}/share/doc/${PORTNAME}

do-install:
	${MKDIR} ${PROGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/adamem ${PROGDIR}
	${LN} -s adamem ${PROGDIR}/cvem
	${INSTALL_DATA} ${WRKSRC}/adamem.snd ${PROGDIR}
	${INSTALL_DATA} ${WRKSRC}/OS7.rom ${PROGDIR}
	${INSTALL_DATA} ${WRKSRC}/WP.rom ${PROGDIR}
	${INSTALL_DATA} ${WRKSRC}/EOS.rom ${PROGDIR}
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/adamem.txt ${DOCDIR}
.endif

.include <bsd.port.mk>
