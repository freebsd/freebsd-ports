# Created by: Andrew Greenwood
# $FreeBSD$

PORTNAME=	dynagui
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	dynagui

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI frontend to the dynamips router simulator

BUILD_DEPENDS=	dynagen:emulators/dynagen

USES=		python
USE_PYTHON=	distutils
IMGDIR=		${STAGEDIR}${PREFIX}/share/${PORTNAME}/img

post-install:
	@${MKDIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/img/* ${IMGDIR}
	${CHMOD} 755 ${STAGEDIR}${PYTHON_SITELIBDIR}/dynagui.py
	${LN} -sf ${PYTHON_SITELIBDIR}/dynagui.py ${STAGEDIR}${PREFIX}/bin/dynagui.py

.include <bsd.port.mk>
