# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	checkheaders
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Checks headers in C/C++ programs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	anastmag

USES=		gmake
MAKE_ARGS=	CXX="${CXX}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
