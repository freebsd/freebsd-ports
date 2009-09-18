# Ports collection makefile for: pear-Text_Diff
# Date created: 18 Feb 2005
# Whom: Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	Text_Diff
PORTVERSION=	1.1.1
CATEGORIES=	devel pear

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Engine for performing and rendering text diffs

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Text
FILES=		Diff.php Diff/Engine/native.php Diff/Engine/shell.php \
		Diff/Engine/string.php Diff/Engine/xdiff.php \
		Diff/Mapped.php Diff/Renderer.php Diff/Renderer/context.php \
		Diff/Renderer/inline.php Diff/Renderer/unified.php \
		Diff/ThreeWay.php Diff3.php
TESTS=		1.txt 2.txt 3.txt 4.txt 5.txt 6.txt context.patch context.phpt \
		context2.phpt diff.phpt inline.phpt inline2.phpt \
		pear_bug12740.phpt pear_bug4879.phpt pear_bug6251.phpt \
		pear_bug6428.phpt string.phpt unified.patch unified.phpt \
		unified2.phpt xdiff.phpt
EXAMPLES=	1.txt \
		2.txt \
		diff.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
