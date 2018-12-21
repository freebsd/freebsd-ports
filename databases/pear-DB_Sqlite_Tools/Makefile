# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DB_Sqlite_Tools
PORTVERSION=	0.1.7
CATEGORIES=	databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	an object oriented interface to backup Sqlite databases

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR} \
		${PEARDIR}/Log/null.php:sysutils/pear-Log@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR} \
		${PEARDIR}/Log/null.php:sysutils/pear-Log@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
