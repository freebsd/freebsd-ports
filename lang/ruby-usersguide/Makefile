# New ports collection makefile for:	ruby-usersguide
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	usersguide
PORTVERSION=	20051121
PORTREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.rubyist.net/~slagell/ruby/ \
		http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-uguide-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby users guide, in HTML format

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

WRKSRC=		${WRKDIR}/rg
NO_BUILD=	yes
DOCSDIR=	${RUBY_MODDOCDIR}

do-install:
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${RUBY_MODDOCDIR}
	@${FIND} -d ${RUBY_MODDOCDIR}/ -type f | \
		${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -d ${RUBY_MODDOCDIR}/ -type d | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir ${RUBY_DOCDIR} 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
