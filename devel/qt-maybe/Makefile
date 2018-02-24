# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qt-maybe
PORTVERSION=	0.0.20151227
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Implementation of sum/option types using QVariant

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	robertknight
GH_TAGNAME=	52b21af

USE_QT5=	core
NO_BUILD=	yes

PLIST_FILES=	include/Either.h include/Maybe.h

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} Either.h Maybe.h \
		${STAGEDIR}${PREFIX}/include)

.include <bsd.port.mk>
