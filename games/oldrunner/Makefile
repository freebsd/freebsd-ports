# New ports collection makefile for:	oldrunner
# Date created:				20 July 2010
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	oldrunner
PORTVERSION=	20100717
CATEGORIES=	games
MASTER_SITES=	ftp://ftp2.culot.org/culot/

MAINTAINER=	frederic@culot.org
COMMENT=	A textmode remake of Broderbund's LodeRunner

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

MAN6=		oldrunner.6
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/oldrunner ${DATADIR_REL}/original.lvl
PLIST_DIRS=	${DATADIR_REL}

post-patch:
	${REINPLACE_CMD} -e '/LEVELS_PATH/s,/usr/local/share/oldrunner,${DATADIR},g' \
		 ${WRKSRC}/cfg.h

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/oldrunner ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/levels/original.lvl ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/oldrunner.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
