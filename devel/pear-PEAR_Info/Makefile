# Ports collection makefile for:  pear-PEAR_Info
# Date created:		2006/07/31
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	PEAR_Info
PORTVERSION=	1.7.0
CATEGORIES=	devel www pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Show Information about your PEAR install and its packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	PEAR
FILES=		Info.php pearinfo.css
TESTS=		pear2_dir/empty_dir.txt sysconf_dir/empty_dir.txt \
		templates/credits.tpl templates/general.tpl \
		templates/packages.tpl user_dir/empty_dir.txt AllTests.php \
		OutputTestCase.php PEAR_Info_TestCase_CustomConfig.php \
		PEAR_Info_TestCase_DefaultConfig.php \
		PEAR_Info_TestCase_Install.php PEAR_Info_TestCase_Output.php
EXAMPLES=	blueskin.css pearinfo3.css pear_info.php pear_info2.php \
		pear_info3.php pear_info4.php pear_info5.php pear_info6.php \
		pear_info7.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
