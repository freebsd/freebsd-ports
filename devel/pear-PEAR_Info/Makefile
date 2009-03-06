# Ports collection makefile for:  pear-PEAR_Info
# Date created:		2006/07/31
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	PEAR_Info
PORTVERSION=	1.9.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Show Information about your PEAR install and its packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
  		${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-PEAR_Info
OPTIONS=	PEAR_PHPUnit3 "PEAR::PHPUnit3 support" on

CATEGORY=	PEAR
FILES=		Info.php pearinfo.css Info/Cli.php scripts/pearinfo
TESTS=		pear2_dir/empty_dir.txt sysconf_dir/empty_dir.txt \
		templates/credits.tpl templates/general.tpl \
		templates/packages.tpl user_dir/empty_dir.txt AllTests.php \
		customConfig.phpt defaultConfig.phpt install.phpt \
		PEAR_Info_TestSuite_Standard.php
EXAMPLES=	blueskin.css pearinfo3.css pear_info.php pear_info2.php \
		pear_info3.php pear_info4.php pear_info5.php pear_info6.php \
		pear_info7.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_PHPUnit3)
RUN_DEPENDS+=	${PEARDIR}/PHPUnit/Framework.php:${PORTSDIR}/devel/pear-PHPUnit3
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
