# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML_QuickForm_Livesearch
PORTVERSION=	0.4.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Element for PEAR::HTML_QuickForm to enable a suggest search

LICENSE=	PHP30

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:devel/pear-HTML_QuickForm@${PHP_FLAVOR} \
		${PEARDIR}/HTML/AJAX.php:www/pear-HTML_AJAX@${PHP_FLAVOR}
RUN_DEPENDS:=	${PEARDIR}/HTML/QuickForm.php:devel/pear-HTML_QuickForm@${PHP_FLAVOR} \
		${PEARDIR}/HTML/AJAX.php:www/pear-HTML_AJAX@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
