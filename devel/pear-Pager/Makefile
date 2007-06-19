# Ports collection makefile for:  pear-Pager
# Date created:			  09 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Pager
PORTVERSION=	2.4.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR data paging class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Pager
FILES=		Common.php Jumping.php Pager.php Sliding.php
EXAMPLES=	example.php Pager_Wrapper.php
TESTS=		all_tests.php pager_include.php pager_jumping_noData_test.php \
		pager_jumping_test.php pager_jumping_tests.php \
		pager_noData_test.php pager_sliding_noData_test.php \
		pager_sliding_notExpanded_test.php pager_sliding_test.php \
		pager_sliding_tests.php pager_test.php pager_test_xss.php \
		pager_tests.php pager_wrapper_include.php pager_wrapper_test.php \
		simple_include.php README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
