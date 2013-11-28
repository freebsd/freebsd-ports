# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_UML
PORTVERSION=	1.6.1
CATEGORIES=	devel

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Class to Create UML Representation of PHP Code

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Console/CommandLine.php:${PORTSDIR}/devel/pear-Console_CommandLine
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes
DEFAULT_PHP_VER=	5
USE_PHP=		spl xsl

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
