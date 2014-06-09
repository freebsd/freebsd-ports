# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mp3tag
PORTVERSION=	1.0
CATEGORIES=	audio ruby
MASTER_SITES=	http://users.cybercity.dk/~dsl8950/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module to manipulate ID3v1.1 tags in MP3 files

USE_RUBY=	yes
USE_RUBY_RDOC=	yes

RUBY_RD_FILES=	mp3tag.rb

NO_BUILD=	yes

DOCS=		README \
		${RUBY_RD_HTML_FILES}

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(require[[:space:]]+')\./mp3tag(.*),\1mp3tag\2," \
		${WRKSRC}/mp3tag_test.rb

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/mp3tag.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mp3tag_test.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
