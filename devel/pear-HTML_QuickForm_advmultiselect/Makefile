# Created by: Chris St Denis <chris@ctgameinfo.com>
# $FreeBSD$

PORTNAME=	HTML_QuickForm_advmultiselect
PORTVERSION=	1.5.0
CATEGORIES=	devel www pear

MAINTAINER=	chris@ctgameinfo.com
COMMENT=	Element for PEAR::HTML_QuickForm that defines a 2 box multi-select

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm \
		${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm \
		${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
