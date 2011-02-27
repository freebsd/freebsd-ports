# New ports collection makefile for:	duke3d-data
# Date Created:				2 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.3drealms.com/share/ \
		ftp://ftp.kiarchive.ru/pub/.1/msdos/games/play/3d/ \
		ftp://ftp.relcom.ru/pub/.1/msdos/games/play/3d/ \
		ftp://ftp.relcom.ru/pub/.1/msdos/games/play/3d/ \
		ftp://ftp.lublin.pl/vol/8/planetquake/planetduke/ \
		ftp://ftp.etsimo.uniovi.es/pub/games/msdos/ \
		ftp://ftp.uniovi.es/pub/games/msdos/ \
		ftp://ftp.ziplink.net/users/rhino/ \
		ftp://ftp.kiae.su/pub/.1/msdos/games/play/3d/
PKGNAMEPREFIX=	${DN3DPKGNAMEPREFIX}
DISTFILES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Duke Nukem 3D Data

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	SHAREWARE "Install shareware game data version 1.3" off

DATADIR=	${DN3DDIR}

.include "Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_SHAREWARE)
DISTFILES+=	3dduke13.zip
PLIST_SUB+=	SHAREWARE=""
.else
PLIST_SUB+=	SHAREWARE="@comment "
SUB_FILES+=	pkg-message
.endif

.if defined(WITH_SHAREWARE)
post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} -qo DN3DSW13.SHR
.endif

do-install:
	${MKDIR} ${DATADIR}
.if defined(WITH_SHAREWARE)
	${INSTALL_DATA} ${WRKSRC}/DUKE3D.GRP ${DATADIR}/duke3d.grp
.else

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
