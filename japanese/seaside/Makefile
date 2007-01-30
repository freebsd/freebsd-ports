# New ports collection makefile for:   	seaside
# Date created:		27 January 2007
# Whom:			mutoh@openedu.org
#
# $FreeBSD$
#

PORTNAME=	seaside
PORTVERSION=	070105
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://swikis.ddo.jp/SeasideJ/
DISTNAME=	Seaside-JPatched${PORTVERSION}
# DISTFILES=	Seaside-JPatched${PORTVERSION}.zip
EXTRACT_ONLY=	Seaside-JPatched${PORTVERSION}.zip

MAINTAINER=	mutoh@openedu.org
COMMENT=	Seaside: squeak based WWW application framework with Japanized patch

RUN_DEPENDS=	squeak:${PORTSDIR}/lang/squeak

NO_BUILD=	yes
USE_ZIP=	yes

DIST_SUBDIR=	squeak

FILES_TO_GZIP=	Seaside-JPatched070105.image \
		Seaside-JPatched070105.changes

PLIST_SUB=	DATADIR=share/squeak
post-extract:
.for file in ${FILES_TO_GZIP}
	(cd ${WRKDIR} && ${GZIP_CMD} ${file})
.endfor

do-install:
.for f in ${FILES_TO_GZIP}
	(cd ${WRKDIR} && ${INSTALL_DATA} ${f}.gz ${PREFIX}/share/squeak/)
.endfor
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
