# Ports collection makefile for:  pear-PHP_Archive
# Date created:			  20 May 2008
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	PHP_Archive
PORTVERSION=	0.11.4
CATEGORIES=	archivers

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Create and Use PHP Archive files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	PHP
FILES=		Archive.php Archive/Creator.php \
		Archive/Exception.php Archive/Manager.php
DATA=		phar_frontcontroller.tpl
TESTS=		eof.phpt filenotfound.phpt filenotfound_phar.phpt \
		filenotfoundtest.php gopearphar.php.inc \
		longfilename.phpt makepearphar.php.inc \
		maketestphars.php.inc new_phar.phar \
		normalstat.phpt normalstat_phar.phpt \
		opendir.phpt pearindex.php phar.log \
		phpt_test.php.inc require_once.phpt \
		require_once_phar.phpt savetest.php \
		seek.phpt seek_phar.phpt streamstat.phpt \
		streamstat_phar.phpt test.php test1.php \
		test_path.php test_phar.phar \
		test_phar2.phar test_require.php \
		test_tar.tar twophars.phpt \
		filenotfound/filenotfound.phar \
		filenotfound/makefilenotfoundphar.php.inc \
		longfilename/longphar.phar \
		longfilename/makelongphar.php.inc \
		opendir/makeopendirphar.php.inc \
		opendir/opendir.phar \
		planet_php/default_phar.php \
		require_once/makerequire_oncephar.php.inc \
		require_once/require_once.phar

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
