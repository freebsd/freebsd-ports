# New ports collection makefile for:	ruby-gdbm
# Date created:		24 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	${RUBY_VERSION}.p3
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	# ${RUBY_VER}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTVERSION:S/.p/-preview/}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTVERSION:R}/ext/gdbm

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.include <bsd.port.post.mk>
