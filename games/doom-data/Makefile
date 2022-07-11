# Created by: Alejandro Pulver <alejandro@varnet.biz>

PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/doom/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Shareware data files for Doom, Doom II, Hexen, Heretic, and Strife

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_SUB=	yes

OPTIONS_MULTI=	WADS
OPTIONS_MULTI_WADS=	DOOM HERETIC HEXEN STRIFE
OPTIONS_DEFAULT=	DOOM

DOOM_DESC=	Install Doom shareware data
HERETIC_DESC=	Install Heretic shareware data
HEXEN_DESC=	Install Hexen shareware data
STRIFE_DESC=	Install Strife shareware data

SUB_FILES=	pkg-message

DATADIR=	${DMDIR}

DOOM_DISTFILES=	doom1.wad.bz2
HERETIC_DISTFILES=	heretic1.wad.bz2
HEXEN_DISTFILES=	hexen.wad.bz2
STRIFE_DISTFILES=	strife0.wad.bz2

.include "Makefile.include"
.include <bsd.port.options.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	@${BZIP2_CMD} -dc ${_DISTDIR}/${f} > ${WRKSRC}/${f:S/.bz2$//}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f:S/.bz2$//} ${STAGEDIR}${DATADIR}/
.endfor

.include <bsd.port.mk>
