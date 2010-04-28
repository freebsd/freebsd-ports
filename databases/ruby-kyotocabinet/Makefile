# New ports collection makefile for:	kyotocabinet-ruby
# Date created:		28 April 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kyotocabinet
PORTVERSION=	1.7
CATEGORIES=	databases ruby
MASTER_SITES=	http://1978th.net/kyotocabinet/rubypkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby (1.9.1+) binding to Kyoto Cabinet

LIB_DEPENDS=	kyotocabinet.2:${PORTSDIR}/databases/kyotocabinet

RUBY_VER=	1.9
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

NO_PACKAGE=	GPL3 incompatibility with Ruby

CONFIGURE_ARGS=	--with-kyotocabinet-dir="${LOCALBASE}" \
		--with-bindir="${LOCALBASE}/bin"

.include <bsd.port.pre.mk>

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/kyotocabinet.so

.if !defined(NOPORTDOCS)
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
PORTEXAMPLES=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

check:
	cd ${BUILD_WRKSRC} && ${SETENV} RUBYLIB=. ${RUBY} maketest.rb

.include <bsd.port.post.mk>
