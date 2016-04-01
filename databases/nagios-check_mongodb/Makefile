# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	check_mongodb
PORTVERSION=	0.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}nagios-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Nagios plugin to check mongodb server

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=0:databases/pymongo

USE_GITHUB=	yes
GH_ACCOUNT=	mzupan
GH_PROJECT=	nagios-plugin-mongodb
GH_TAGNAME=	9d17373
USES=		python shebangfix
SHEBANG_FILES=	${WRKSRC}/check_mongodb.py
NO_BUILD=	yes
PLIST_FILES=	libexec/nagios/check_mongodb

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_mongodb.py ${STAGEDIR}${PREFIX}/libexec/nagios/check_mongodb

.include <bsd.port.mk>
