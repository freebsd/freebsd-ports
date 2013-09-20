# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sexp
PORTVERSION=	0.2.1
PORTREVISION=	0
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A ruby library to work with s-expressions

RUN_DEPENDS=	rubygem-rparsec>0:${PORTSDIR}/devel/rubygem-rparsec

USE_RUBY=	yes
NO_BUILD=	yes

SADIR=		${RUBY_SITELIBDIR}

EXAMPLES=	example.rb

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/sexp.rb ${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/sexpressions.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
