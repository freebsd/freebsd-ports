# New ports collection makefile for:	gramofile
# Date created:		Fri Jan 28 18:40:38 CET 2000
# Whom:			nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

PORTNAME=	gramofile
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://panic.et.tudelft.nl/~costar/gramofile/

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	Audio recording and tick/scratch reduction for e.g. vinyl records

ALL_TARGET=	gramofile
USE_GMAKE=	yes

post-patch:
.for file in bplay.c sndfunc.c
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/bplaysrc/${file} > ${WRKSRC}/bplaysrc/${file}.new
	@${MV} ${WRKSRC}/bplaysrc/${file}.new ${WRKSRC}/bplaysrc/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gramofile ${WRKSRC}/bplay_gramo ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/gramofile
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gramofile
	${LN} -s bplay_gramo ${PREFIX}/bin/brec_gramo

.include <bsd.port.mk>
