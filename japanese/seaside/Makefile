# Created by: mutoh@openedu.org
# $FreeBSD$

PORTNAME=	seaside
DISTVERSION=	080908-sq39
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://swikis.ddo.jp/SeasideJ/
DISTNAME=	Seaside-JPatched${DISTVERSION}
EXTRACT_ONLY=	Seaside-JPatched${DISTVERSION}.zip

MAINTAINER=	mutoh@openedu.org
COMMENT=	Seaside: squeak based WWW application framework with Japanized patch

RUN_DEPENDS=	squeak:${PORTSDIR}/lang/squeak

USES=		zip
NO_BUILD=	yes

DIST_SUBDIR=	squeak

FILES_TO_INSTALL=	Seaside-JPatched${DISTVERSION}.image \
		Seaside-JPatched${DISTVERSION}.changes

PLIST_SUB=	DATADIR=lib/squeak \
		SEASIDEVERSION=${DISTVERSION}

NO_STAGE=	yes
do-install:
.for f in ${FILES_TO_INSTALL}
	(cd ${WRKDIR} && ${INSTALL_DATA} ${f} ${PREFIX}/lib/squeak/)
.endfor
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
