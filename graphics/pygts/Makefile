# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pygts
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python binding for GNU Triangulated Surface(GTS) Library

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	gts.5:${PORTSDIR}/graphics/gts

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USES=			pkgconfig

NO_STAGE=	yes
.include <bsd.port.mk>
