# New ports collection makefile for:	ruby-bsdconv
# Date created:		13 Oct 2011
# Whom:			buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	7.1
CATEGORIES=	converters ruby
MASTER_SITES=	https://github.com/buganini/ruby-${PORTNAME}/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Ruby wrapper for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	bsdconv:${PORTSDIR}/converters/bsdconv

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

GITVERSION=	a3437bf
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-ruby-${PORTNAME}-${GITVERSION}

.include <bsd.port.mk>
