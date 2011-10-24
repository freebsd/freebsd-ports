# New ports collection makefile for:	Ruby/Mp3Tag
# Date created:		30 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mp3tag
PORTVERSION=	1.0
CATEGORIES=	audio ruby
MASTER_SITES=	http://users.cybercity.dk/~dsl8950/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby module to manipulate ID3v1.1 tags in MP3 files

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
	${MKDIR} ${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/mp3tag.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mp3tag_test.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
