# New ports collection makefile for:   	seaside
# Date created:		27 January 2007
# Whom:			mutoh@openedu.org
#
# $FreeBSD$
#

PORTNAME=	seaside
DISTVERSION=	070930-sq38
PORTREVISION=	1
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://swikis.ddo.jp/SeasideJ/
DISTNAME=	Seaside-JPatched${DISTVERSION}
EXTRACT_ONLY=	Seaside-JPatched${DISTVERSION}.zip

MAINTAINER=	mutoh@openedu.org
COMMENT=	Seaside: squeak based WWW application framework with Japanized patch

RUN_DEPENDS=	squeak:${PORTSDIR}/lang/squeak

NO_BUILD=	yes
USE_ZIP=	yes

DIST_SUBDIR=	squeak

FILES_TO_GZIP=	Seaside-JPatched20${DISTVERSION}.image \
		Seaside-JPatched20${DISTVERSION}.changes

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
