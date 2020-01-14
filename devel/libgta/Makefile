# Created by: lbartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgta
PORTVERSION=	1.0.8
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH/gta

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Portable library that implements the GTA file format

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		pathfix gmake tar:xz
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgta.so

.include <bsd.port.mk>
