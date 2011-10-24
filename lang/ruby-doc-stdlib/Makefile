# New ports collection makefile for:	ruby-doc-stdlib
# Date created:		2006-08-04
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	stdlib
PORTVERSION=	0.10.1
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.ruby-doc.org/download/stdlib/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}doc-
DISTNAME=	ruby-doc-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation for the Ruby language standard library

USE_RUBY=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${RUBY_DOCDIR}/
	@(cd ${WRKSRC} && \
		${RUBY} install.rb --force --doc-base ${RUBY_DOCDIR}/)

plist:
	truncate -s0 pkg-plist

	@${FIND} -ds ${RUBY_MODDOCDIR}/ ! -type d | \
		${SED} 's,^${RUBY_MODDOCDIR},%%RUBY_MODDOCDIR%%,' \
		>> pkg-plist

	@${FIND} -ds ${RUBY_MODDOCDIR}/ -type d | ${SORT} -r | ${SED} -E -e \
		's,^${RUBY_MODDOCDIR}(.*),@dirrm %%RUBY_MODDOCDIR%%\1,' \
		>> pkg-plist

	@${ECHO_CMD} "@dirrmtry %%RUBY_DOCDIR%%" >> pkg-plist

.include <bsd.port.post.mk>
