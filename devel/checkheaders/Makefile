# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	checkheaders
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checks headers in C/C++ programs

USES=		gmake zip
MAKE_ARGS=	CXX="${CXX}"

PLIST_FILES=	bin/${PORTNAME}

LICENSE=	GPLv3

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
