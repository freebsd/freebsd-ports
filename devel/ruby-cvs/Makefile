# New ports collection makefile for:	Ruby/CVS
# Date created:		20 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cvs
PORTVERSION=	0.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://cvs.m17n.org/cgi-bin/viewcvs/ruby-${PORTNAME}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}\?tarball=1\&only_with_tag=ruby-${PORTNAME}-${PORTVERSION:S/./_/g}\&cvsroot=ruby\&
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to provide a high level interface to a CVS repository

# optional, but strongly suggested
#RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/flex.so:${PORTSDIR}/devel/ruby-flex_rb

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	cvs.rb diff.rb tempdir.rb
RUBY_SHEBANG_FILES=	${WRKSRC}/viztree ${WRKSRC}/reviz/reviz

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

DOCS=		README TODO ${RUBY_RD_HTML_FILES}

.include <bsd.port.pre.mk>

post-extract:
.for f in ${RUBY_RD_FILES}
	cd ${WRKSRC}; ${LN} -sf lib/${f}
.endfor

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/reviz
	${INSTALL_DATA} ${WRKSRC}/viztree ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/reviz/* ${RUBY_MODEXAMPLESDIR}/reviz/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
