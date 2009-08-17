# Ports collection makefile for:	rubygem-sexp_processor
# Date created:				Feb 03 2009
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	sexp_processor
PORTVERSION=	3.0.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	parsetree

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Generic sexp processing tools

BUILD_DEPENDS=	rubygem-hoe>=1.8.2:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
