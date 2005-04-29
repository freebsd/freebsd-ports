# New ports collection makefile for:	gnofract4d
# Date created:				30 Dec 1999
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnofract4d
PORTVERSION=	2.6
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weird GNOME fractal generator

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui lthack
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
USE_GCC=	3.4

post-patch:
# where to install libraries
	${REINPLACE_CMD} -e 's,\(^install_lib =\).*,\1${PREFIX}/lib/${PORTNAME},' ${WRKSRC}/setup.cfg
# contain in DATADIR ('share/foobar/gnofract4d' -> 'share/gnofract4d/foobar')
	${FIND} ${WRKSRC} -name '*.py' -exec \
		${REINPLACE_CMD} -e "s,\([\"']\)share/\([^/]*\)/gnofract4d\1,\1${DATADIR:C/${PREFIX}\///}/\2\1," {} \;
# libraries again
	${REINPLACE_CMD} -e "s,gnofract4d-${PORTVERSION},${PORTNAME}," ${WRKSRC}/gnofract4d
# where to install docs
	${REINPLACE_CMD} -e "s,share/doc/gnofract4d-%s/'.*,${DOCSDIR:C/${PREFIX}\///}'\,," ${WRKSRC}/setup.py

.include <bsd.port.mk>
