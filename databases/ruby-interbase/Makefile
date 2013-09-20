# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	interbase
PORTVERSION=	0.5.2
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.rowlandresearch.com/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	fb-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby interface to Firebird/Interbase library

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_FIREBIRD=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

#CONFIGURE_ARGS=	--with-interbase-include-dir="${LOCALBASE}/include" \
#		--with-interbase-lib-dir="${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-opt-dir=${LOCALBASE}
INSTALL_TARGET=	site-install

DOCS_EN=	README

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's/gdslib/fbclient/' ${WRKSRC}/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
