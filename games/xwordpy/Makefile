# Ports collection makefile for:	xwordpy
# Date created:				Dec. 1, 2008
# Whom:					bf2006a@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	xwordpy
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://x-word.org/
DISTNAME=	xword-${PORTVERSION}

MAINTAINER=	bf1783@gmail.com
COMMENT=	An application for solving crossword puzzles in the Across Lite format

USE_GNOME=	pygtk2
USE_PYTHON=	24+
NO_BUILD=	yes

PLIST_DIRS=	%%DATADIR%%
PLIST_FILES=	bin/xwordpy \
		%%DATADIR%%/crossword-check-all.png \
		%%DATADIR%%/crossword-check.png \
		%%DATADIR%%/crossword-clock.png \
		%%DATADIR%%/crossword-solve.png \
		%%DATADIR%%/layout-rtb.png

post-patch:
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|\'${DATADIR}\'|g" \
		-e "s|/usr/bin/python|${PYTHON_CMD}|g" \
		${WRKSRC}/xword

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/xword ${PREFIX}/bin/xwordpy
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && for f in *.png ; do ${INSTALL_DATA} ${WRKSRC}/$$f ${DATADIR} ; \
	done)

.include <bsd.port.mk>
