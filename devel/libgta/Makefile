# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libgta
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH/gta

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Libgta is a portable library that implements the GTA file format

OPTIONS_DEFINE=	DOCS

USE_XZ=		yes
GNU_CONFIGURE=	yes
USES=		pathfix gmake
USE_LDCONFIG=	yes

regression-test test: build
	cd ${WRKSR}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
