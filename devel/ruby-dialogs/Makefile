# New ports collection makefile for:	rubyDialogs
# Date created:		2 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dialogs
PORTVERSION=	1.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://bluesine.com/archives/software/ruby/rubyDialogs/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}.rb ${PORTNAME}.html
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/dialogs.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/dialogs
	${INSTALL_DATA} ${WRKDIR}/dialogs.html ${RUBY_DOCDIR}/dialogs/
.endif

.include <bsd.port.mk>
