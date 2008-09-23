# New ports collection makefile for:	pear-PHP_ArrayOf
# Date created:		2008-09-22
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PHP_ArrayOf
PORTVERSION=	0.2.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Abstract class package to create arrays of specific element types

BUILD_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		PHP/ArrayOf.php PHP/ArrayOfInterface.php \
		PHP/ArrayOf/Exception.php
TESTS=		AcceptValue.phpt ArrayOfInteger.inc RejectValue.phpt \
		__construct_subclass.phpt ArrayAccess_Brackets.phpt \
		ArrayOfString.inc __construct_ArrayObject.phpt \
		ArrayAccess_Methods.phpt Countable.phpt __construct_array.phpt \
		ArrayOfAnything.inc IteratorAggregate.phpt \
		__construct_self.phpt
DOCS=		example1.php
_DOCSDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
