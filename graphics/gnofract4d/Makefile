# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	gnofract4d
PORTVERSION=	3.14
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Weird GNOME fractal generator

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

LICENSE=	BSD

USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui lthack \
		pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

CFLAGS+=	-I${LOCALBASE}/include
PORTDOCS=	README COPYING
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFODIR=	${PYTHON_SITELIBDIR}

NO_STAGE=	yes
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
	@${REINPLACE_CMD} -e '249,251d' ${WRKSRC}/setup.py

	# fixup library detection
	@${REINPLACE_CMD} -e "s/libpng/libpng15/" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
	     -e "s,/usr/include/jpeglib.h,${LOCALBASE}/include/jpeglib.h," \
	     ${WRKSRC}/setup.py

	# png14
	@${REINPLACE_CMD} -e "s/png_infopp_NULL/NULL/g" \
		-e "s/png_bytepp_NULL/NULL/g" \
		-e "s/int_p_NULL/NULL/g" \
		${WRKSRC}/fract4d/c/imageIO.cpp

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
