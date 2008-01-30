# Ports collection makefile for:	rubygem-parsetree
# Date created:				13 April 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	parsetree
PORTVERSION=	2.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
DISTNAME=	ParseTree-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby parse tree tools

BUILD_DEPENDS=	rubygem-inline>=3.6.0:${PORTSDIR}/devel/rubygem-inline \
		rubygem-hoe>=1.4.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

GEM_NAME=       ${DISTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
