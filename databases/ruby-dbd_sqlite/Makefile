# New ports collection makefile for:	dbd_sqlite for DBD-for-Ruby
# Date created:		15 November 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_sqlite
PORTVERSION=	${RUBY_DBI_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	sqlite.1:${.CURDIR}/../sqlite
RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR}

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=ext/${PORTNAME}

DOCS_EN=	ext/${PORTNAME}/README

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

post-patch:
	${RUBY} -i- -pe 'gsub "/usr/local", "${LOCALBASE}"' \
		${WRKSRC}/ext/${PORTNAME}/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${RUBY_DBI_PORTNAME}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${RUBY_DBI_PORTNAME}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
