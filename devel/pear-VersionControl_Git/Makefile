# Ports collection makefile for:	pear-VersionControl_Git
# Date created: 			11 Feb, 2010
# Whom: 				Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	VersionControl_Git
PORTVERSION=	0.4.3
CATEGORIES=	devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	OO interface to handle Git repository

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		VersionControl/Git.php \
		VersionControl/Git/Component.php \
		VersionControl/Git/Exception.php \
		VersionControl/Git/Object.php \
		VersionControl/Git/Object/Blob.php \
		VersionControl/Git/Object/Commit.php \
		VersionControl/Git/Object/Tree.php \
		VersionControl/Git/Util/Command.php \
		VersionControl/Git/Util/RevListFetcher.php

DOCS=		intro.xml tutorial.xml
_DOCSDIR=	doc

TESTS=		README \
		VersionControl_GitTest.php \
		VersionControl_Git_ComponentTest.php \
		VersionControl_Git_ObjectTest.php \
		VersionControl_Git_Object_BlobTest.php \
		VersionControl_Git_Object_CommitTest.php \
		VersionControl_Git_Object_TreeTest.php \
		VersionControl_Git_Util_CommandTest.php \
		checkFixtures.php
_TESTSDIR=	test

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
