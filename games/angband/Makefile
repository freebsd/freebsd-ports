# New ports collection makefile for:   angband
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	angband
PORTVERSION=	2.9.0
CATEGORIES=	games
MASTER_SITES=	ftp://export.andrew.cmu.edu/angband/Source/ \
		ftp://ftp.greyhelm.com/pub/Games/Angband/Angband-2.7.x/Source/ \
		ftp://ftp.sunet.se/pub/games/Angband/Source/ \
		ftp://mirror.aarnet.edu.au/pub/games/roguelike/angband/Source/ \
		ftp://export.andrew.cmu.edu/angband/Extra/ \
		ftp://ftp.greyhelm.com/pub/Games/Angband/Angband-2.7.x/Extra/ \
		ftp://ftp.sunet.se/pub/games/Angband/Extra/ \
		ftp://mirror.aarnet.edu.au/pub/games/roguelike/angband/Extra/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mph
DISTNAME=	angband-290
DISTFILES=	angband-290-src.tar.gz angband-290-graf.zip \
		angband-290-data.tar.gz
EXTRACT_ONLY=	angband-290-src.tar.gz

MAINTAINER=	mph@freebsd.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_X_PREFIX=	yes
DIST_SUBDIR=	angband

post-extract:
	(cd ${WRKSRC}/lib/xtra/graf && unzip ${DISTDIR}/${DIST_SUBDIR}/angband-290-graf.zip)

pre-patch:
	${CP} ${WRKSRC}/src/makefile.std ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/angband ${PREFIX}/bin/angband
	find ${WRKSRC}/lib -name delete.me -delete
	${MKDIR} ${PREFIX}/lib/X11/angband
	(cd ${WRKSRC}/lib && ${TAR} cf - * ) | (cd ${PREFIX}/lib/X11/angband && tar xf - )
	(cd ${PREFIX} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/angband-290-data.tar.gz)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/X11/angband
	(cd ${PREFIX}/lib/X11/angband && \
		${CHMOD} 555 apex bone data edit file help info xtra ; \
		${CHMOD} 1777 save user \
		)
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 555 /dev/null ${PREFIX}/lib/X11/angband/apex/scores.raw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
