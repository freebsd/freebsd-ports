# New ports collection makefile for:    dynagui
# Date created:                          5 February 2009
# Whom:                                 Andrew Greenwood
#
# $FreeBSD$
#

PORTNAME=	dynagui
PORTVERSION=	0.4
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	dynagui

MAINTAINER=	greenwood.andy@gmail.com
COMMENT=	GUI frontend to the dynamips router simulator

BUILD_DEPENDS=	dynagen:${PORTSDIR}/emulators/dynagen-devel

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
IMGDIR=		${PREFIX}/share/${PORTNAME}/img

post-install:
	${MKDIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/img/* ${IMGDIR}
	${CHMOD} 755 ${PYTHON_SITELIBDIR}/dynagui.py
	${LN} -sf ${PYTHON_SITELIBDIR}/dynagui.py ${PREFIX}/bin/dynagui.py

.include <bsd.port.mk>
