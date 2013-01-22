# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	boxer
PORTVERSION=	0.3.8
CATEGORIES=	graphics
MASTER_SITES=	SF/boxc/${PORTNAME:C/^b/B/}%20-%20the%20Box%20GUI/${DISTNAME}/ \
		http://boxc.sourceforge.net/_images/:icons
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		cycloid.png:icons
DIST_SUBDIR=	box
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	GUI for Box the figure description language

LICENSE=	GPLv3 # (or later)

RUN_DEPENDS=	box:${PORTSDIR}/graphics/box
EXTRACT_DEPENDS=pngtopnm:${PORTSDIR}/graphics/netpbm

USE_GNOME=	pygtk2

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

DESKTOP_ENTRIES="Boxer" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Graphics;VectorGraphics;" false

post-extract:
	@(cd ${WRKSRC} && \
		${LOCALBASE}/bin/pngtopnm ${DISTDIR}/${DIST_SUBDIR}/cycloid.png | \
		${LOCALBASE}/bin/pamscale .218 | ${LOCALBASE}/bin/pnmtopng > ${PORTNAME}.png)

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
