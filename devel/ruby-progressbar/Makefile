# New ports collection makefile for:	ruby-progressbar
# Date created:		11 April 2010
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	progressbar
PORTVERSION=	0.9
CATEGORIES=	devel ruby
MASTER_SITES=	http://0xcc.net/ruby-progressbar/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A ruby library to display progressbars

USE_RUBY=	yes
NO_BUILD=	yes

PLIST_FILES=	${RUBY_SITELIBDIR:C,^${PREFIX}/?,,g}/progressbar.rb
DOCSDIR=	${RUBY_MODDOCDIR}
.if !defined(NOPORTDOCS)
PORTDOCS=	progressbar.en.rd progressbar.ja.rd ChangeLog
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/progressbar.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
