# New ports collection makefile for:	RDBC1
# Date created:		19 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rdbc1
PORTVERSION=	001103
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://member.nifty.ne.jp/guion/SOFT/RDBC/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby Database Connectivity

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/postgres.so:${.CURDIR}/../ruby-postgres

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${CP} -R ${WRKSRC}/doc/en/* ${RUBY_MODDOCDIR}/
	${CP} -R ${WRKSRC}/doc/ja/* ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
