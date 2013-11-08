# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	HTML_Select_Common
PORTVERSION=	1.2.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Some small PEAR classes to handle common <select> lists

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common	\
		${PEARDIR}/I18N/Common.php:${PORTSDIR}/devel/pear-I18N
RUN_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common	\
		${PEARDIR}/I18N/Common.php:${PORTSDIR}/devel/pear-I18N

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
