# Created by: mutoh@openedu.org
# $FreeBSD$

PORTNAME=	pharo
DISTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/30620/
DISTNAME=	Pharo-${DISTVERSION}-${SVNVERSION}
EXTRACT_ONLY=	Pharo-${DISTVERSION}-${SVNVERSION}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smalltalk-inspired language and environment

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	squeak:lang/squeak

SVNVERSION=	14438

NO_BUILD=	yes
USES=		zip

DIST_SUBDIR=	squeak

FILES_DIR=	${WRKDIR}/Pharo-${DISTVERSION}-${SVNVERSION}/
FILES_TO_INSTALL=Pharo-${DISTVERSION}.image \
		Pharo-${DISTVERSION}.changes \
		PharoV10.sources
PLIST_FILES=	lib/squeak/Pharo-${DISTVERSION}.image \
		lib/squeak/Pharo-${DISTVERSION}.changes \
		lib/squeak/PharoV10.sources

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/squeak
	${INSTALL_DATA} ${FILES_TO_INSTALL:S,^,${FILES_DIR}/,} ${STAGEDIR}${PREFIX}/lib/squeak

.include <bsd.port.mk>
