# New Ports collection makefile for:	blockrage
# Date created:		2012-04-28
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	blockrage
PORTVERSION=	0.2.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Block Rage is falling blocks game with a 2-player hotseat mode

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl image mixer
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/blockrage

MAN6=		blockrage.6

PORTDATA=	*
PORTDOCS=	ChangeLog KNOWN_BUGS README TODO

do-install:
# Scripts
	@${PRINTF} "#!/bin/sh\n\ncd ${DATADIR} &&\
		./blockrage\n" > ${WRKDIR}/blockrage.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/blockrage.sh ${PREFIX}/bin/blockrage
# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/blockrage ${DATADIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6
# Data
.for d in data blockrage-fhs.rc blockrage.cfg blockrage.rc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

# Documentations
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
