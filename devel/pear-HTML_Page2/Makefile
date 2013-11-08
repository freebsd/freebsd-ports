# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	HTML_Page2
PORTVERSION=	0.6.1
CATEGORIES=	devel www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}beta

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR base class for XHTML page generation

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common

PEAR_AUTOINSTALL=yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
