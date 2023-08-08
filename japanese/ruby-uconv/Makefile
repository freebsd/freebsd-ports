PORTNAME=	uconv
PORTVERSION=	0.5.3
CATEGORIES=	japanese converters ruby
MASTER_SITES=	http://www.yoshidam.net/
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Unicode conversion library with Japanese codesets support for Ruby
WWW=		http://www.yoshidam.net/Ruby.html #uconv

LICENSE=	RUBY
LICENSE_FILE=	${WRKSRC}/README

USES=		ruby:extconf

MAKE_ARGS=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROG="${INSTALL_PROGRAM}"
INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-patch:
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
	@${REINPLACE_CMD} -e 's|fdeclspec|fdeclspec -Wno-error=incompatible-function-pointer-types|g' \
				${WRKSRC}/extconf.rb
.endif

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.post.mk>
