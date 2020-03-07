# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	MDB_QueryTool
PORTVERSION=	1.2.3
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR OO-interface for easily retrieving and modifying data in a DB

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PEARDIR}/MDB.php:databases/pear-MDB@${PHP_FLAVOR} \
		${PEARDIR}/Log/null.php:sysutils/pear-Log@${PHP_FLAVOR}
RUN_DEPENDS:=	${PEARDIR}/MDB.php:databases/pear-MDB@${PHP_FLAVOR} \
		${PEARDIR}/Log/null.php:sysutils/pear-Log@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
