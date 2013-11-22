# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	0.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://cvs.m17n.org/viewcvs/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}.tar.gz\?only_with_tag=ruby-${PORTNAME}-${PORTVERSION:S/./_/g}\&view=tar
DIST_SUBDIR=	ruby

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A Ruby library to provide a high level interface to a CVS repository

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

BROKEN=		Does not fetch

# optional, but strongly suggested
#RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/flex.so:${PORTSDIR}/devel/ruby-flex_rb

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	cvs.rb diff.rb tempdir.rb
RUBY_SHEBANG_FILES=	${WRKSRC}/viztree ${WRKSRC}/reviz/reviz

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

DOCS=		README TODO ${RUBY_RD_HTML_FILES}

NO_STAGE=	yes
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
