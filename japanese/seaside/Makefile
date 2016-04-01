# Created by: mutoh@openedu.org
# $FreeBSD$

PORTNAME=	seaside
DISTVERSION=	080908-sq39
PORTREVISION=	1
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://swikis.ddo.jp/SeasideJ/
DISTNAME=	Seaside-JPatched${DISTVERSION}
EXTRACT_ONLY=	Seaside-JPatched${DISTVERSION}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Seaside: squeak based WWW application framework with Japanized patch

RUN_DEPENDS=	squeak:lang/squeak

USES=		zip
NO_BUILD=	yes

DIST_SUBDIR=	squeak

FILES_TO_INSTALL=	Seaside-JPatched${DISTVERSION}.image \
		Seaside-JPatched${DISTVERSION}.changes

PLIST_SUB=	DATADIR=lib/squeak \
		SEASIDEVERSION=${DISTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/squeak
.for f in ${FILES_TO_INSTALL}
	(cd ${WRKDIR} && ${INSTALL_DATA} ${f} ${STAGEDIR}${PREFIX}/lib/squeak/)
.endfor

.include <bsd.port.mk>
