# New ports collection makefile for:	gnofract4d
# Date created:				30 Dec 1999
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnofract4d
PORTVERSION=	3.10
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	SF

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weird GNOME fractal generator

USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui lthack \
		pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PORTDOCS=	README COPYING
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFODIR=	${PYTHON_SITELIBDIR}

.include <bsd.port.pre.mk>

post-patch:
	# where to install libraries
	@${REINPLACE_CMD} \
		-e 's,\(^install_lib =\).*,\1${PREFIX}/lib/${PORTNAME},' \
		${WRKSRC}/setup.cfg

	# contain in DATADIR
	# ('share/foobar/gnofract4d' -> # 'share/gnofract4d/foobar')
	@${FIND} ${WRKSRC} -name '*.py' -exec \
		${REINPLACE_CMD} \
		-e "s,\([\"']\)share/\([^/]*\)/gnofract4d\1,\1${DATADIR:C/${PREFIX}\///}/\2\1," {} \;

	# libraries again
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/gnofract4d

	# fix NOPORTDOCS
	@${REINPLACE_CMD} -e '233,235d' ${WRKSRC}/setup.py

	# fixup library detection
	@${REINPLACE_CMD} -e "s/libpng/libpng12/" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
	     -e "s,/usr/include/jpeglib.h,${LOCALBASE}/include/jpeglib.h," \
	     ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
