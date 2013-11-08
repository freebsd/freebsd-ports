# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	HTML_Template_Sigma
PORTVERSION=	1.2.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR template API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	ctype

PEAR_AUTOINSTALL=	yes

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
