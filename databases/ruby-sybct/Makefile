# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	sybct
PORTVERSION=	0.2.12
CATEGORIES=	databases ruby
MASTER_SITES=	http://enjoy1.bb-east.ne.jp/~tetsu/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module for accessing Sybase databases

LIB_DEPENDS=	libtds.so:${PORTSDIR}/databases/freetds

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USES=		iconv

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%ICONV_LIB%%|${ICONV_LIB}|' \
		${WRKSRC}/extconf.rb

post-install:
	@${MKDIR} ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/sy*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README-ja.txt ${RUBY_MODDOCDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.html ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/ja/*.html ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
