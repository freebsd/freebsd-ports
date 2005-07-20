# Ports collection makefile for:	gem-activerecord
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	1.11.1
CATEGORIES=	databases ruby

MAINTAINER=	jw@innerewut.de
COMMENT=	Object-relational mapping layer for Rails MVC Framework

MASTER_SITES=	http://rubyforge.org/frs/download.php/5163/

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-1.1.1.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
