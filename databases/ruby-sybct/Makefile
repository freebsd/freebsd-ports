# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	sybct
PORTVERSION=	0.2.12
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://enjoy1.bb-east.ne.jp/~tetsu/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module for accessing Sybase databases

LIB_DEPENDS=	libsybdb.so:databases/freetds

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USES=		iconv

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%ICONV_LIB%%|${ICONV_LIB}|' \
		${WRKSRC}/extconf.rb

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/sy*.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README-ja.txt ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.html ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/ja/*.html ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
