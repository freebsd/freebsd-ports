# Ports collection makefile for:  pear-PEAR_PackageFileManager
# Date created:			  23 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PEAR_PackageFileManager
PORTVERSION=	1.5.2
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to maintain PEAR packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_PHP_COMPATINFO "PEAR::PHP_CompatInfo support" off \
		PEAR_XML_TREE "PEAR::XML_Tree support" off

CATEGORY=	PEAR
FILES=		PackageFileManager/Cvs.php PackageFileManager/File.php \
		PackageFileManager/Perforce.php \
		PackageFileManager/SimpleGenerator.php \
		PackageFileManager/Svn.php \
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
		addRole/test_invalid_role.phpt \
		addRole/test_valid_role.phpt \
		footest/blarfoo/blartest.txt \
		footest/subfoo/subsubfoo/boo.txt \
		footest/subfoo/test11.txt footest/subfoo/test12.txt \
		footest/testCVS/testEntries \
		footest/testCVS/testEntries.Extra footest/.test \
		footest/test1.txt footest/test2.txt \
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
		PEAR_PackageFileManager_CVS/footest/blarfoo/blartest.txt \
		PEAR_PackageFileManager_CVS/footest/subfoo/subsubfoo/boo.txt \
		PEAR_PackageFileManager_CVS/footest/subfoo/test11.txt \
		PEAR_PackageFileManager_CVS/footest/subfoo/test12.txt \
		PEAR_PackageFileManager_CVS/footest/testCVS/testEntries \
		PEAR_PackageFileManager_CVS/footest/testCVS/testEntries.Extra \
		PEAR_PackageFileManager_CVS/footest/.test \
		PEAR_PackageFileManager_CVS/footest/test1.txt \
		PEAR_PackageFileManager_CVS/footest/test2.txt \
		PEAR_PackageFileManager_CVS/setup.php.inc \
		PEAR_PackageFileManager_CVS/test_dirList_invalid.phpt \
		PEAR_PackageFileManager_CVS/test_dirList_valid.phpt \
		PEAR_PackageFileManager_CVS/test_dirList_valid_with_ignore.phpt \
		PEAR_PackageFileManager_CVS/test_dirList_valid_with_include.phpt \
		PEAR_PackageFileManager_CVS/test_general_valid1.phpt \
		PEAR_PackageFileManager_CVS/test_general_valid2.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_complex_multiple_no.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_complex_multiple_pass.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_complex_no.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_emptyarray.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_nonarray.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_simple_dir_no.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_simple_dir_pass.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_simple_no.phpt \
		PEAR_PackageFileManager_File/checkIgnore/test_simple_pass.phpt \
		PEAR_PackageFileManager_File/dirList/test_bug1217/0 \
		PEAR_PackageFileManager_File/dirList/test_bug1217/firstfile.php \
		PEAR_PackageFileManager_File/dirList/test_bug1217/fourthfile.php \
		PEAR_PackageFileManager_File/dirList/test_bug1217/secondfile.php \
		PEAR_PackageFileManager_File/dirList/test_bug1217.phpt \
		PEAR_PackageFileManager_File/dirList/test_invalid.phpt \
		PEAR_PackageFileManager_File/dirList/test_valid.phpt \
		PEAR_PackageFileManager_File/dirList/test_valid_addhiddenfiles.phpt \
		PEAR_PackageFileManager_File/dirList/test_valid_with_ignore.phpt \
		PEAR_PackageFileManager_File/dirList/test_valid_with_include.phpt \
		PEAR_PackageFileManager_File/getFileList/test_valid.phpt \
		PEAR_PackageFileManager_File/getRegExpableSearchString/test_1.phpt \
		PEAR_PackageFileManager_File/getRegExpableSearchString/test_dir_regexp.phpt \
		PEAR_PackageFileManager_File/getRegExpableSearchString/test_file_regexp.phpt \
		PEAR_PackageFileManager_File/setDir/test_concept.phpt \
		PEAR_PackageFileManager_File/setupDirs/test_concept.phpt \
		PEAR_PackageFileManager_File/setupDirs/test_valid.phpt \
		PEAR_PackageFileManager_File/setupIgnore/test_complex.phpt \
		PEAR_PackageFileManager_File/setupIgnore/test_complex_multiple.phpt \
		PEAR_PackageFileManager_File/setupIgnore/test_emptyarray.phpt \
		PEAR_PackageFileManager_File/setupIgnore/test_nonarray.phpt \
		PEAR_PackageFileManager_File/setupIgnore/test_simple.phpt \
		PEAR_PackageFileManager_File/setupIgnore/test_simple_0.phpt \
		PEAR_PackageFileManager_File/setupIgnore/test_simple_dir.phpt \
		PEAR_PackageFileManager_File/setup.php.inc \
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

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
