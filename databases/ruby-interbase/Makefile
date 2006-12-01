# New ports collection makefile for:	ruby-interbase
# Date created:		8 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	interbase
PORTVERSION=	0.5.2
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.rowlandresearch.com/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	fb-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Ruby interface to Firebird/Interbase library

USE_FIREBIRD=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

#CONFIGURE_ARGS=	--with-interbase-include-dir="${LOCALBASE}/include" \
#		--with-interbase-lib-dir="${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-opt-dir=${LOCALBASE}
INSTALL_TARGET=	site-install

DOCS_EN=	README

post-patch:
	${REINPLACE_CMD} -e 's/gdslib/fbclient/' ${WRKSRC}/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
