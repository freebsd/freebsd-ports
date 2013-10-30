# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygments.rb
PORTVERSION=	0.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Exposes the pygments syntax highlighter to Ruby

RUN_DEPENDS=	rubygem-posix-spawn>=0.3.6:${PORTSDIR}/devel/rubygem-posix-spawn \
		rubygem-yajl-ruby>=1.1.0:${PORTSDIR}/devel/rubygem-yajl-ruby \
		pygmentize:${PORTSDIR}/textproc/py-pygments

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
