# New ports collection makefile for:	ruby-postgres
# Date created:		17 Nov 2009
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pg
PORTVERSION=	0.9.0
CATEGORIES=	databases ruby
MASTER_SITES=	http://cdn.bitbucket.org/ged/ruby-pg/downloads/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ruby interface to PostgreSQL library

USE_PGSQL=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/ext
CONFIGURE_ARGS=	--with-pgsql-include-dir="${LOCALBASE}/include"
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog Contributors README
DOCS_JA=	README.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
