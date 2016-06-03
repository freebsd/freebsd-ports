# Created by: bf2006a@yahoo.com
# $FreeBSD$

PORTNAME=	xwordpy
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://x-word.org/
DISTNAME=	xword-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Application for solving crossword puzzles in the Across Lite format

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
USE_GNOME=	pygtk2
USES=		python
NO_BUILD=	yes
NO_ARCH=	yes

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
	${INSTALL_SCRIPT} ${WRKSRC}/xword ${STAGEDIR}${PREFIX}/bin/xwordpy
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
