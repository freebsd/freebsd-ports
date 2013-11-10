# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	phpDox
PORTVERSION=	0.5.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.netpirates.net/get/
PKGNAMEPREFIX=	pear-TheSeer_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Documentation generation framework and tool

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.9.2:${PORTSDIR}/devel/pear \
		pear-TheSeer_DirectoryScanner>=1.1.0:${PORTSDIR}/devel/pear-TheSeer_DirectoryScanner \
		pear-TheSeer_fDOMDocument>=1.2.3:${PORTSDIR}/devel/pear-TheSeer_fDOMDocument \
		pear-TheSeer_fXSL>=1.0.4:${PORTSDIR}/devel/pear-TheSeer_fXSL \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-pdepend_staticReflection>=0.2.1:${PORTSDIR}/devel/pear-pdepend-staticReflection
RUN_DEPENDS=	pear>=1.9.2:${PORTSDIR}/devel/pear \
		pear-TheSeer_DirectoryScanner>=1.1.0:${PORTSDIR}/devel/pear-TheSeer_DirectoryScanner \
		pear-TheSeer_fDOMDocument>=1.2.3:${PORTSDIR}/devel/pear-TheSeer_fDOMDocument \
		pear-TheSeer_fXSL>=1.0.4:${PORTSDIR}/devel/pear-TheSeer_fXSL \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-pdepend_staticReflection>=0.2.1:${PORTSDIR}/devel/pear-pdepend-staticReflection

USE_PHP=	dom tokenizer xsl iconv
PEAR_CHANNEL=	theseer
PEAR_AUTOINSTALL=	yes

IGNORE_WITH_PHP=52

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
