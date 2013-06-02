# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PEAR_PackageFileManager2
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	PEAR class to maintain PEAR packages

LICENSE=	BSD

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/PEAR/PackageFileManager/Plugins.php:${PORTSDIR}/devel/pear-PEAR_PackageFileManager_Plugins
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/PEAR/PackageFileManager/Plugins.php:${PORTSDIR}/devel/pear-PEAR_PackageFileManager_Plugins

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
