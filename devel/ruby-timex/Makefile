# New ports collection makefile for:	Ruby/timex
# Date created:		2 November 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	timex
PORTVERSION=	0.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://cvs.m17n.org/cgi-bin/viewcvs/${PORTNAME}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	timex-${PORTVERSION}${EXTRACT_SUFX}\?tarball=1\&only_with_tag=${PORTNAME}-${PORTVERSION:S/./_/g}\&cvsroot=ruby\&
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${RUBY_RD} timex.rb > timex.html
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/timex.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/timex.html ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
