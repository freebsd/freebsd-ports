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
COMMENT=	TZFile handling library for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	tzfile.rb

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		${RUBY_RD_HTML_FILES}

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/tzfile.rb ${RUBY_SITELIBDIR}/

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
