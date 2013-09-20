# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	pgplot
PORTVERSION=	0.1.3
PORTREVISION=	4
CATEGORIES=	graphics ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb_${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby interface to PGPLOT graphics library

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot
BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_FORTRAN=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-x11-dir="${LOCALBASE}" --with-gfortranlib="gfortran -L`${CAT} ${WRKSRC}/LIBDIR`/../../.."
INSTALL_TARGET=	site-install

DOCS_EN=	FuncUsage	README.en
DOCS_JA=	README.ja
EXAMPLES_EN=	pgdemo*.rb	test/*.rb

NO_STAGE=	yes
pre-configure:
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
