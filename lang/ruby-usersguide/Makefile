# New ports collection makefile for:	ruby-usersguide
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-usersguide
PORTVERSION=	20010131
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.cs.iastate.edu/~slagell/ruby/
DISTNAME=	${PORTNAME:S/usersguide/uguide/}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

WRKSRC=		${WRKDIR}/rg
NO_BUILD=	yes

DOCDIR=		${RUBY_DOCDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${DOCDIR}

.include <bsd.port.mk>
