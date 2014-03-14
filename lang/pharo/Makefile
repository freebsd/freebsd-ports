# Created by: mutoh@openedu.org
# $FreeBSD$

PORTNAME=	pharo
DISTVERSION=	1.4
CATEGORIES=	lang
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/30620/
DISTNAME=	Pharo-${DISTVERSION}-${SVNVERSION}
EXTRACT_ONLY=	Pharo-${DISTVERSION}-${SVNVERSION}.zip

MAINTAINER=	mutoh@openedu.org
COMMENT=	Pharo is Smalltalk-inspired environment

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	squeak:${PORTSDIR}/lang/squeak

SVNVERSION=	14438

NO_BUILD=	yes
USES=		zip

SHAREMODE=	644

DIST_SUBDIR=	squeak

FILES_DIR=	${WRKDIR}/Pharo-${DISTVERSION}-${SVNVERSION}/
FILES_TO_INSTALL=Pharo-${DISTVERSION}.image \
		Pharo-${DISTVERSION}.changes \
		PharoV10.sources
PLIST_FILES=	lib/squeak/Pharo-${DISTVERSION}.image \
		lib/squeak/Pharo-${DISTVERSION}.changes \
		lib/squeak/PharoV10.sources

NO_STAGE=	yes
do-install:
.for f in ${FILES_TO_INSTALL}
	(cd ${FILES_DIR} && ${INSTALL_DATA} ${f} ${PREFIX}/lib/squeak/)
.endfor

.include <bsd.port.mk>
