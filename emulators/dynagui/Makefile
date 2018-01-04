# Created by: Andrew Greenwood
# $FreeBSD$

PORTNAME=	dynagui
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	dynagui

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI frontend to the dynamips router simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dynagen:emulators/dynagen

USES=		python:2.7 shebangfix
SHEBANG_FILES=	dynagui.py
USE_PYTHON=	distutils
IMGDIR=		${STAGEDIR}${PREFIX}/share/${PORTNAME}/img
NO_ARCH=	yes

post-install:
	@${MKDIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/img/* ${IMGDIR}
	${CHMOD} 755 ${STAGEDIR}${PYTHON_SITELIBDIR}/dynagui.py
	${LN} -sf ${PYTHON_SITELIBDIR}/dynagui.py ${STAGEDIR}${PREFIX}/bin/dynagui.py

.include <bsd.port.mk>
