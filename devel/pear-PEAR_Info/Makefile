# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	PEAR_Info
PORTVERSION=	1.9.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Show Information about your PEAR install and its packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
  		${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
  		${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs

LATEST_LINK=	pear-PEAR_Info
OPTIONS_DEFINE=	PEAR_PHPUNIT3
OPTIONS_DEFAULT=	PEAR_PHPUNIT3
PEAR_PHPUNIT3_DESC=	PEAR::PHPUnit3 support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_PHPUNIT3}
RUN_DEPENDS+=	${PEARDIR}/PHPUnit/Autoload.php:${PORTSDIR}/devel/pear-PHPUnit3
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
