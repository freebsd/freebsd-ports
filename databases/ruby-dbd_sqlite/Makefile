# New ports collection makefile for:	dbd_sqlite for DBD-for-Ruby
# Date created:		15 November 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_sqlite
PORTVERSION=	${RUBY_DBI_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_DBI_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SQLite driver for DBI-for-Ruby

LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2
RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR}

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

SLAVE_PORT=	yes
MASTER_PORT=	databases/ruby-dbi

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=ext/${PORTNAME}

DOCS_EN=	ext/${PORTNAME}/README

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

post-patch:
	${RUBY} -i- -pe "gsub 'dir_config \'sqlite\'', 'dir_config \'sqlite\', \'${LOCALBASE}\''" \
		${WRKSRC}/ext/${PORTNAME}/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
