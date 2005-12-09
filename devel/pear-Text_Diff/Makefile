# Ports collection makefile for: pear-Text_Diff
# Date created: 18 Feb 2005
# Whom: Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	Text_Diff
PORTVERSION=	0.1.1
CATEGORIES=	devel pear

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Engine for performing and rendering text diffs

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Text
FILES=		Diff.php \
		Diff3.php \
		Diff/Renderer.php \
		Diff/Renderer/inline.php \
		Diff/Renderer/unified.php
TESTS=		1.txt \
		2.txt \
		diff.phpt \
		inline.phpt \
		unified.phpt
EXAMPLES=	1.txt \
		2.txt \
		diff.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
