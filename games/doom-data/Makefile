# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/doom/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
EXTRACT_SUFX=	.bz2
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Shareware data files for Doom, Doom II, Hexen, Heretic, and Strife

USE_BZIP2=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOOM HERETIC HEXEN STRIFE
OPTIONS_DEFAULT=	DOOM
DOOM_DESC=	Install Doom shareware data
HERETIC_DESC=	Install Heretic shareware data
HEXEN_DESC=	Install Hexen shareware data
STRIFE_DESC=	Install Strife shareware data

SUB_FILES=	pkg-message

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${DMDIR}

DOOM_WAD=	doom1.wad
HERETIC_WAD=	heretic1.wad
HEXEN_WAD=	hexen.wad
STRIFE_WAD=	strife0.wad

.include "Makefile.include"

.include <bsd.port.options.mk>

.for f in ${OPTIONS_DEFINE}
.if ${PORT_OPTIONS:M${f}}
DISTFILES+=	${${f}_WAD}${EXTRACT_SUFX}
PLIST_SUB+=	${f}=""
.   else
PLIST_SUB+=	${f}="@comment "
.   endif
.endfor

.if ${DISTFILES} == ""
.   undef DIST_SUBDIR
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
.for f in ${OPTIONS_DEFINE}
.   if ${PORT_OPTIONS:M${f}}
	@${BZIP2_CMD} -dc ${_DISTDIR}/${${f}_WAD}${EXTRACT_SUFX} > \
		${WRKDIR}/${${f}_WAD}
.   endif
.endfor

do-install:
	@${MKDIR} ${DATADIR}
.for f in ${OPTIONS_DEFINE}
.   if ${PORT_OPTIONS:M${f}}
	${INSTALL_DATA} ${WRKSRC}/${${f}_WAD} ${DATADIR}
.   endif
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
