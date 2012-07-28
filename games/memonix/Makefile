# New ports collection makefile for:	memonix
# Date created:		12 Jul 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	memonix
PORTVERSION=	1.6.070713
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.viewizard.com/download/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	MemonixSourceCode_${PORTVERSION:S/./_/g:S/_/./}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} memx16.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Brain teasers, puzzle, and memory games for kids in one pack

LICENSE=	unknown GPLv2
LICENSE_COMB=	dual
LICENSE_NAME_unknown=	Freeware License
LICENSE_PERMS_unknown=	${_LICENSE_PERMS_DEFAULT}
LICENSE_FILE_unknown=	${WRKDIR}/Memonix/License
LICENSE_DISTFILE_unknown=	memx16.tar.gz
LICENSE_DISTFILE_GPLv2=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_FILE_GPLv2=	${WRKSRC}/License.txt

USE_CMAKE=	yes
USE_ZIP=	yes
USE_SDL=	sdl mixer image
USE_GL=		yes

WRKSRC=		${WRKDIR}/MemonixSourceCode

PLIST_FILES=	bin/Memonix %%DATADIR%%/gamedata.vfs
PLIST_DIRS=	%%DATADIR%%

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${DISTDIR}/memx16.tar.gz

post-patch:
	@${REINPLACE_CMD} -e '/strcpy(ProgrammDir,/ s|\./|${DATADIR}/|' \
		 ${WRKSRC}/src/Main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Memonix ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/Memonix/gamedata.vfs ${DATADIR}

.include <bsd.port.mk>
