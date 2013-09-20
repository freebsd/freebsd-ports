# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	bdb1
PORTVERSION=	0.2.3
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Ruby interface to Berkeley DB revision 1.8x with full feature support

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

NOPORTDOCS=	# XXX

INSTALL_TARGET=	site-install

DOCS=		Changes \
		README.en \
		bdb1.html \
		bdb1.rd \
		docs/*.html \
		docs/*.rd \
		docs/doc

NO_STAGE=	yes
test regression-test check:
	${MAKE} -C ${WRKSRC} test

post-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} rdoc
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
pre-everything::
	########################################################
	# Although it is now possible to compile ${PORTNAME}
	# against Ruby-${RUBY_VER}, the resulting binary is not
	# fully functional due to changes in Ruby API.
	# Use of Ruby-1.8 is recommended for full compatibility.
	########################################################
.elif ${RUBY_VER} == 1.8
post-build: test
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64 (signal 6)
.endif

.include <bsd.port.post.mk>
