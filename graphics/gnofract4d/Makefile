# New ports collection makefile for:	gnofract4d
# Date created:				30 Dec 1999
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnofract4d
PORTVERSION=	3.0
PORTREVISION=	0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weird GNOME fractal generator

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui lthack \
		pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GCC=	3.4

BROKEN=		leaves files around after deinstall

PLIST_FILES=	bin/gnofract4d

PORTDOCS=	*

.include <bsd.port.pre.mk>

post-patch:
# where to install libraries
	@${REINPLACE_CMD} -e 's,\(^install_lib =\).*,\1${PREFIX}/lib/${PORTNAME},' ${WRKSRC}/setup.cfg
# contain in DATADIR ('share/foobar/gnofract4d' -> 'share/gnofract4d/foobar')
	@${FIND} ${WRKSRC} -name '*.py' -exec \
		${REINPLACE_CMD} -e "s,\([\"']\)share/\([^/]*\)/gnofract4d\1,\1${DATADIR:C/${PREFIX}\///}/\2\1," {} \;
# libraries again
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/gnofract4d
# where to install docs
	@${REINPLACE_CMD} -e "s,share/doc/gnofract4d-%s/'.*,${DOCSDIR:C/${PREFIX}\///}'\,," ${WRKSRC}/setup.py

post-install:
.for dir in ${PREFIX}/lib/gnofract4d ${PREFIX}/share/gnofract4d ${PREFIX}/share/gnome/help/gnofract4d
	@${FIND} ${dir} ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
