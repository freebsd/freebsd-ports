# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	check_mongodb
PORTVERSION=	0.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}nagios-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Nagios plugin to check mongodb server

RUN_DEPENDS=	pymongo>=0:${PORTSDIR}/databases/pymongo

USE_GITHUB=	yes
GH_ACCOUNT=	mzupan
GH_PROJECT=	nagios-plugin-mongodb
GH_COMMIT=	9d17373
GH_TAGNAME=	${GH_COMMIT}
USE_PYTHON=	yes
USES=		shebangfix
SHEBANG_FILES=	${WRKSRC}/check_mongodb.py
python_OLD_CMD=	"/usr/bin/env\ python"
python_CMD=	${PYTHON_CMD}
NO_BUILD=	yes
PLIST_FILES=	libexec/nagios/check_mongodb
PLIST_DIRSTRY=	libexec/nagios

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_mongodb.py ${STAGEDIR}${PREFIX}/libexec/nagios/check_mongodb

.include <bsd.port.mk>
