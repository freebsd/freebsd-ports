# New ports collection makefile for:	ruby-interbase
# Date created:		8 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	interbase
PORTVERSION=	0.04
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.rowlandresearch.com/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	skv@freebsd.org

LIB_DEPENDS=	gds:${PORTSDIR}/databases/firebird

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-interbase-include-dir="${LOCALBASE}/firebird/include" \
		--with-interbase-lib-dir="${LOCALBASE}/firebird/lib"
INSTALL_TARGET=	site-install

DOCS_EN=	README
DOCS_JA=	README.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
