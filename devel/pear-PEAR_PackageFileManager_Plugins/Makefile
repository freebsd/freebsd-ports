# New ports collection makefile for:	pear-PEAR_PackageFileManager_Plugins
# Date created:		2009-10-17
# Whom:			Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PEAR_PackageFileManager_Plugins
PORTVERSION=	1.0.1
CATEGORIES=	devel www pear

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	The plugins for PEAR_PackageFileManager

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	PEAR

FILES=		PackageFileManager/Cvs.php \
		PackageFileManager/File.php \
		PackageFileManager/Perforce.php \
		PackageFileManager/Plugins.php \
		PackageFileManager/Svn.php
TESTS=		PEAR_PackageFileManager_CVS/setup.php.inc \
		PEAR_PackageFileManager_CVS/teardown.php.inc \
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
		phpt_test.php.inc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
