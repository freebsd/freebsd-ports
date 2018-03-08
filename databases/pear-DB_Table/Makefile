# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	DB_Table
PORTVERSION=	1.5.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR object-oriented interface to a database table

USES=		pear

OPTIONS_DEFINE=	PEAR_HTML_QUICKFORM PEAR_DB PEAR_MDB2
PEAR_HTML_QUICKFORM_DESC=	PEAR::HTML_QuickForm support
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB2_DESC=	PEAR::MDB2 support

PEAR_HTML_QUICKFORM_RUN_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:devel/pear-HTML_QuickForm@${PHP_FLAVOR}
PEAR_DB_RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR}
PEAR_MDB2_RUN_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR}

.include <bsd.port.mk>
