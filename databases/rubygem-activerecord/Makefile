# Ports collection makefile for:	gem-activerecord
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	1.13.2
CATEGORIES=	databases ruby

MAINTAINER=	jw@innerewut.de
COMMENT=	Object-relational mapping layer for Rails MVC Framework

MASTER_SITES=	http://rubyforge.org/frs/download.php/7641/

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-1.2.5.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
