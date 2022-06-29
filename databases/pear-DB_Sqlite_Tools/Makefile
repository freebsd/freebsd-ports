# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	DB_Sqlite_Tools
PORTVERSION=	0.1.7
CATEGORIES=	databases www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented interface to backup SQLite databases

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR} \
		${PEARDIR}/Log/null.php:sysutils/pear-Log@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR} \
		${PEARDIR}/Log/null.php:sysutils/pear-Log@${PHP_FLAVOR}

USES=		pear

CONFLICTS_INSTALL=	php[0-9][0-9]-pear-Crypt_HMAC2 \
			php[0-9][0-9]-pear-DB_Sqlite_Tools # share/pear/DB/Sqlite/Tools.php share/pear/generate_package_xml.php

.include <bsd.port.mk>
