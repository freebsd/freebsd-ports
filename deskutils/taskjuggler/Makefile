# Created by: Dean Povey <povey@wedgetail.com>
# $FreeBSD$

PORTNAME=	taskjuggler
PORTVERSION=	3.4.0
CATEGORIES=	deskutils
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A project management tool for UNIX based operating systems

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-mail>=2.4.3:${PORTSDIR}/mail/rubygem-mail \
		rubygem-term-ansicolor>=1.0.7:${PORTSDIR}/devel/rubygem-term-ansicolor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.8
IGNORE=	requires Ruby 1.9.3
.endif

.include <bsd.port.post.mk>
