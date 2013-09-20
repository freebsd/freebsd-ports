# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	dialogs
PORTVERSION=	1.1
CATEGORIES=	devel ruby
MASTER_SITES=	LOCAL/fenner/ruby-contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A simple Ruby interface to dialog(1)

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKDIR}/dialogs.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKDIR}/dialogs.html ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
