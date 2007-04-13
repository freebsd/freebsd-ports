# Ports collection makefile for:	rubygem-parsetree
# Date created:				13 April 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	parsetree
PORTVERSION=	1.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ParseTree-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby parse tree tools

BUILD_DEPENDS=	rubygem-inline>=3.2.0:${PORTSDIR}/devel/rubygem-inline
RUN_DEPENDS=	${BUILD_DEPENDS}

GEM_NAME=       ${DISTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
