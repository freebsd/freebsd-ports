# Created by: Gerrit Beine (<gerrit.beine@gmx.de>)
# $FreeBSD$

PORTNAME=	HTML_QuickForm2
PORTVERSION=	0.6.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP5 rewrite of the HTML_QuickForm package

BUILD_DEPENDS=	${PEARDIR}/HTML/Common2.php:${PORTSDIR}/devel/pear-HTML_Common2
RUN_DEPENDS=	${PEARDIR}/HTML/Common2.php:${PORTSDIR}/devel/pear-HTML_Common2

DEFAULT_PHP_VER=5
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
