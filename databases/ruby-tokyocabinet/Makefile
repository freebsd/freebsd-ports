PORTNAME=	tokyocabinet
PORTVERSION=	1.31
CATEGORIES=	databases ruby
MASTER_SITES=	https://dbmx.net/${PORTNAME}/rubypkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	dgerow@afflictions.org
COMMENT=	Ruby interface to the Tokyo Cabinet DB engine
WWW=		https://dbmx.net/tokyocabinet/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

USES=	ruby:extconf

INSTALL_TARGET=	site-install

DOCS=	doc/*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
