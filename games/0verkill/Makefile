# New ports collection makefile for:    0verkill
# Date created:         5 May 2001
# Whom:                 Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	0verkill
PORTVERSION=	0.15
CATEGORIES=	games
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

HAS_CONFIGURE=	YES

post-patch:
	${SED} "s|@PREFIX@|${PREFIX}|g" ${WRKSRC}/cfg.h > ${WRKSRC}/cfg.h.done
	${MV} ${WRKSRC}/cfg.h.done ${WRKSRC}/cfg.h
	${SED} "s|grx/|${PREFIX}/share/0verkill/grx/|g" ${WRKSRC}/data/sprites.dat \
		> ${WRKSRC}/data/sprites.dat.done
	${MV} ${WRKSRC}/data/sprites.dat.done ${WRKSRC}/data/sprites.dat

do-install:
	${MKDIR} ${PREFIX}/share/0verkill \
		${PREFIX}/share/doc/0verkill ${PREFIX}/share/0verkill/data \
		${PREFIX}/share/0verkill/grx
	cd ${WRKSRC} && ${INSTALL_PROGRAM} 0verkill ${PREFIX}/bin
	cd ${WRKSRC} && for f in avi bot editor server test_server; do \
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin/0verkill-$$f; \
	done
	cd ${WRKSRC}/data && ${INSTALL_DATA} banner.dat dynamic.dat room.dat \
		sprites.dat ${PREFIX}/share/0verkill/data
	${INSTALL_DATA} ${WRKSRC}/grx/* ${PREFIX}/share/0verkill/grx
	cd ${WRKSRC}/doc && ${INSTALL_DATA} AUTHORS README.html avi.txt \
		bot.txt doc.html ${PREFIX}/share/doc/0verkill

.include <bsd.port.mk>
