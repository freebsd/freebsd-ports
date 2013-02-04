# Created by: Gerrit Beine (<gerrit@beine-computer.de>)
# $FreeBSD$

PORTNAME=	HTML_QuickForm
PORTVERSION=	3.2.13
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Provide methods for creating, validating, and processing HTML forms

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS:=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
