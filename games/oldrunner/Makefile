# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	oldrunner
PORTVERSION=	20120131
CATEGORIES=	games
MASTER_SITES=	LOCAL/culot

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Textmode remake of Broderbund's LodeRunner

LICENSE=	BSD2CLAUSE

USES=		ncurses gmake
HAS_CONFIGURE=	yes
MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/oldrunner ${DATADIR_REL}/original.lvl man/man6/oldrunner.6.gz
PLIST_DIRS=	${DATADIR_REL}

post-patch:
	${REINPLACE_CMD} -e '/LEVELS_PATH/s,/usr/local/share/oldrunner,${DATADIR},g' \
		 ${WRKSRC}/cfg.h

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/oldrunner ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/levels/original.lvl ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/oldrunner.6 ${STAGEDIR}${MANPREFIX}/man/man6

.include <bsd.port.mk>
