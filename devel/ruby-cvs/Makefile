# New ports collection makefile for:	Ruby/CVS
# Date created:		20 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cvs
PORTVERSION=	0.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://cvs.m17n.org/cgi-bin/viewcvs/ruby-${PORTNAME}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}\?tarball=1\&only_with_tag=ruby-${PORTNAME}-${PORTVERSION:S/./_/g}\&cvsroot=ruby\&
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

# optional, but strongly suggested
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/flex.so:${PORTSDIR}/devel/ruby-flex_rb

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

RUBY_SHEBANG_FILES=	${WRKSRC}/viztree ${WRKSRC}/reviz/reviz

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

DOCS=	README TODO cvs.html tempdir.html

do-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${RUBY_RD} lib/cvs.rb > cvs.html
	cd ${WRKSRC} && ${RUBY_RD} lib/cvs/tempdir.rb > tempdir.html
.endif

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/reviz
	${INSTALL_DATA} ${WRKSRC}/viztree ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/reviz/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/reviz/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
