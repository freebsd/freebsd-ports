# New ports collection makefile for:	Ruby-Racc
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	racc
PORTVERSION=	1.4.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-all
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	racc-runtime

CONFIGURE_ARGS=	--with=racc

WRKDIR_RACC=	${WRKSRC}/packages/racc

post-extract:
	${CP} -p ${WRKDIR_RACC}/misc/* ${WRKDIR_RACC}/bin/

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR_RACC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKDIR_RACC}/doc.en/* ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKDIR_RACC}/doc.ja/* ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
