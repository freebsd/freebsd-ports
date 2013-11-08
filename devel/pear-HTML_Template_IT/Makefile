# Created by: Alex Miller (<asm@asm.kiev.ua>)
# $FreeBSD$

PORTNAME=	HTML_Template_IT
PORTVERSION=	1.3.0
PORTEPOCH=	1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Integrated template API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
