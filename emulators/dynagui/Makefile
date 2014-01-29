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

BUILD_DEPENDS=	dynagen:${PORTSDIR}/emulators/dynagen

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
IMGDIR=		${PREFIX}/share/${PORTNAME}/img

NO_STAGE=	yes
post-install:
	${MKDIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/img/* ${IMGDIR}
	${CHMOD} 755 ${PYTHON_SITELIBDIR}/dynagui.py
	${LN} -sf ${PYTHON_SITELIBDIR}/dynagui.py ${PREFIX}/bin/dynagui.py

.include <bsd.port.mk>
