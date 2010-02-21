# New ports collection makefile for:	pear-PEAR_PackageFileManager2
# Date created:		2009-10-17
# Whom:			Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PEAR_PackageFileManager2
PORTVERSION=	1.0.1
CATEGORIES=	devel www pear

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	PEAR class to maintain PEAR packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	PEAR

FILES=		PackageFileManager2.php
EXAMPLES=	basicConvert.php \
		detectDependencies.php \
		easyMigration.php \
		makepackage.php \
		updatepackage.php
TESTS=		importFromPackageFile1/packagefiles/package_foo.xml \
		importFromPackageFile1/setup.php.inc \
		importFromPackageFile1/test.phpt \
		importOptions/packagefiles/package_foo.xml \
		importOptions/setup.php.inc \
		importOptions/test.phpt \
		setOptions/existingpackagexml/package_changelog.xml \
		setOptions/existingpackagexml/package_nochangelog.xml \
		setOptions/setup.php.inc \
		setOptions/test_existingpackagexml_changelog.phpt \
		setOptions/test_existingpackagexml_nochangelog.phpt \
		setOptions/test_existingpackagexml_unknownchannel.phpt \
		setOptions/test_newpackagexml.phpt \
		setOptions/test_nobaseinstalldir.phpt \
		setOptions/test_nonrealpackagedirectory.phpt \
		setOptions/test_nopackagedirectory.phpt \
		writePackageFile/packagefiles/package1.xml \
		writePackageFile/packagefiles/Server.php \
		writePackageFile/setup.php.inc \
		writePackageFile/test_addchangelog.phpt \
		writePackageFile/test_updatechangelog.phpt \
		phpt_test.php.inc \
		setup.php.inc
.include <bsd.port.pre.mk>

post-patch:
	${MV} ${WRKSRC}/tests/PEAR_PackageFileManager2/* ${WRKSRC}/tests
	${RM} -R ${WRKSRC}/tests/PEAR_PackageFileManager2

##build-install:
##	${RM} -R ${PREFIX}/share/pear/tests/PEAR_PackageFileManager2

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
