# New ports collection makefile for:	Ruby/TZFile
# Date created:		8 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tzfile
PORTVERSION=	0.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://cvs.m17n.org/cgi-bin/viewcvs/${PORTNAME}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	TZFile-${PORTVERSION}${EXTRACT_SUFX}\?tarball=1\&only_with_tag=${PORTNAME}-${PORTVERSION:S/./_/g}\&cvsroot=ruby\&
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY_RD2} tzfile.rb > tzfile.html
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/tzfile.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/tzfile.html ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
