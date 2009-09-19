# New ports collection makefile for:	doom-data
# Date created:				21 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/doom/ \
		http://distfiles.officialunix.com/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
EXTRACT_SUFX=	.bz2
DISTFILES=	#
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Doom data files (Doom, Doom II, Hexen, Heretic and Strife)

USE_BZIP2=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	DOOM "Install Doom shareware data" on \
		HERETIC "Install Heretic shareware data" off \
		HEXEN "Install Hexen shareware data" off \
		STRIFE "Install Strife shareware data" off

SUB_FILES=	pkg-message

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${DMDIR}

LIST=		DOOM HERETIC HEXEN STRIFE

DOOM_WAD=	doom1.wad
HERETIC_WAD=	heretic1.wad
HEXEN_WAD=	hexen.wad
STRIFE_WAD=	strife0.wad

.include "Makefile.include"

.include <bsd.port.pre.mk>

.for f in ${LIST}
.   if defined(WITH_${f}) || !defined(WITHOUT_${f})
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
.for f in ${LIST}
.   if defined(WITH_${f}) || !defined(WITHOUT_${f})
	@${BZIP2_CMD} -dc ${_DISTDIR}/${${f}_WAD}${EXTRACT_SUFX} > \
		${WRKDIR}/${${f}_WAD}
.   endif
.endfor

do-install:
	@${MKDIR} ${DATADIR}
.for f in ${LIST}
.   if defined(WITH_${f}) || !defined(WITHOUT_${f})
	${INSTALL_DATA} ${WRKSRC}/${${f}_WAD} ${DATADIR}
.   endif
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
