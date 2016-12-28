# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mp3tag
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio ruby
MASTER_SITES=	LOCAL/sunpoet/ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module to manipulate ID3v1.1 tags in MP3 files

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(require[[:space:]]+')\./mp3tag(.*),\1mp3tag\2," \
		${WRKSRC}/mp3tag_test.rb

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/mp3tag.rb ${STAGEDIR}${RUBY_SITELIBDIR}/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} README ${STAGEDIR}${RUBY_MODDOCDIR}/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mp3tag_test.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
