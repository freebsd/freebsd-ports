# New ports collection makefile for:   angband
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	angband
PORTVERSION=	2.8.3
CATEGORIES=	games
MASTER_SITES=	ftp://export.andrew.cmu.edu/angband/Source/ \
		http://people.FreeBSD.org/~mph/distfiles/
DISTFILES=	angband-283.tar.gz ext-x11-283.tar.gz angband-data.tar.gz

MAINTAINER=	mph@freebsd.org

USE_X_PREFIX=	yes
DIST_SUBDIR=	angband

EXTRACT_ONLY=	angband-283.tar.gz ext-x11-283.tar.gz

EXTSRC=		${WRKDIR}/ext-x11-283

pre-patch:
	${CP} ${WRKSRC}/src/Makefile.std ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/angband ${PREFIX}/bin/angband
	${MKDIR} ${PREFIX}/lib/X11/angband
	(cd ${WRKSRC}/lib && ${TAR} cf - * ) | (cd ${PREFIX}/lib/X11/angband && tar xf - )
	(cd ${PREFIX} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/angband-data.tar.gz)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/X11/angband
	(cd ${PREFIX}/lib/X11/angband && \
		${CHMOD} 555 apex bone data edit file help info xtra ; \
		${CHMOD} 1777 save user \
		)
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 555 /dev/null ${PREFIX}/lib/X11/angband/apex/scores.raw
	${INSTALL_DATA} ${EXTSRC}/lib/xtra/tiles.raw \
		${PREFIX}/lib/X11/angband/xtra
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
