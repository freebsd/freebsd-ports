# Ports collection makefile for:  pear-PEAR_PackageFileManager
# Date created:			  23 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PEAR_PackageFileManager
PORTVERSION=	1.7.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to maintain PEAR packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_PHP_COMPATINFO "PEAR::PHP_CompatInfo support" off \
		PEAR_XML_TREE "PEAR::XML_Tree support" off

CATEGORY=	PEAR

FILES=		PackageFileManager/SimpleGenerator.php \
		PackageFileManager/XMLOutput.php PackageFileManager.php
EXAMPLES=	createPhpDocumentor_package.xml.php generatePackage.xml.php
TESTS=		addConfigureOption/test_invalid_nosetoptions.phpt \
		addConfigureOption/test_valid_add1.phpt \
		addConfigureOption/test_valid_add2.phpt \
		addConfigureOption/test_valid_replace.phpt \
		addDependency/test_invalid_nosetoptions.phpt \
		addDependency/test_invalid_phppkg.phpt \
		addDependency/test_valid_add_php.phpt \
		addDependency/test_valid_add_pkg_explicit.phpt \
		addDependency/test_valid_add_pkg_implicit.phpt \
		addDependency/test_valid_replace.phpt \
		addMaintainer/test_invalid_nosetoptions.phpt \
		addMaintainer/test_invalid_wrongrole.phpt \
		addMaintainer/test_valid_add.phpt \
		addMaintainer/test_valid_replace.phpt \
		addReplacement/test_invalid_replacement.phpt \
		addReplacement/test_valid_replacement.phpt \
		generateNewPackageXML/test_invalid_nodescription.phpt \
		generateNewPackageXML/test_invalid_nopackage.phpt \
		generateNewPackageXML/test_invalid_nosummary.phpt \
		generateNewPackageXML/test_valid_simple.phpt \
		generateNewPackageXML/test_valid_withdeps.phpt \
		generateNewPackageXML/test_valid_withdepsfalse.phpt \
		generateNewPackageXML/test_valid_withmaintainers.phpt \
		generateNewPackageXML/test_valid_withmaintainersfalse.phpt \
		getExistingPackageXML/test_invalid_notexists_nopackage.phpt \
		getExistingPackageXML/test_invalid_wrongdir.phpt \
		getExistingPackageXML/test_valid_deps.phpt \
		getExistingPackageXML/test_valid_maintainers.phpt \
		getExistingPackageXML/test_valid_simple.phpt \
		importOptions/test_invalid.phpt \
		importOptions/test_valid.phpt \
		PEAR_PackageFileManager_XMLOutput/test_valid1.phpt \
		setOptions/test_invalid_badfilelistgenerator1.phpt \
		setOptions/test_invalid_badfilelistgenerator2.phpt \
		setOptions/test_invalid_badfilelistgenerator3.phpt \
		setOptions/test_invalid_filelistgeneratorcustom.phpt \
		setOptions/test_invalid_nobaseinstalldir.phpt \
		setOptions/test_invalid_nopackagedir.phpt \
		setOptions/test_invalid_nostate.phpt \
		setOptions/test_invalid_noversion.phpt \
		setOptions/test_valid_filelistgeneratorcustom.phpt \
		setOptions/test_valid_filelistgeneratorcvs.phpt \
		setOptions/test_valid_filelistgeneratorfile.phpt \
		Bad_file.php phpt_test.php.inc setup.php.inc test1_package.xml \
		Test_file.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_PHP_COMPATINFO)
RUN_DEPENDS+=	${PEARDIR}/PHP/CompatInfo.php:${PORTSDIR}/devel/pear-PHP_CompatInfo
.endif

.if defined(WITH_PEAR_XML_TREE)
RUN_DEPENDS+=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
