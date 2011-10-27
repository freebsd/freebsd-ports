# Ports collection makefile for:	rubygem-activemodel
# Date created:				1 September 2010
# Whom:						Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

PORTNAME=	activemodel
PORTVERSION=	3.1.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A toolkit for building modeling frameworks

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-builder>=3.0.0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-bcrypt-ruby>=3.0.0:${PORTSDIR}/security/rubygem-bcrypt-ruby \
		rubygem-i18n>=0.6.0:${PORTSDIR}/devel/rubygem-i18n

USE_RUBY=   yes
USE_RUBYGEMS=   yes
RUBYGEM_AUTOPLIST=  yes

.include <bsd.port.mk>
