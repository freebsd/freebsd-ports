# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Image_Barcode
PORTVERSION=	1.1.3
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for barcode generation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	gd

LATEST_LINK=	pear-${PORTNAME}

OPTIONS_DEFINE=		PEAR_PHP_COMPAT
PEAR_PHP_COMPAT_DESC=	"PEAR::PHP_Compat support"

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPEAR_PHP_COMPAT}
RUN_DEPENDS+=	${PEARDIR}/PHP/Compat.php:${PORTSDIR}/devel/pear-PHP_Compat
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
