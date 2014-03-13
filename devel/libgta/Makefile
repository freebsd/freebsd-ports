# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libgta
PORTVERSION=	1.0.5
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH/gta

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Portable library that implements the GTA file format

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		pathfix gmake tar:xz
USE_LDCONFIG=	yes

regression-test test: build
	cd ${WRKSR}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgta.so

.include <bsd.port.mk>
