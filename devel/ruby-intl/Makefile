# New ports collection makefile for:	Ruby-intl
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	intl
PORTVERSION=	0.11
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.page.sannet.ne.jp/hirata-naoto/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/intl/po/
	${INSTALL_DATA} ${WRKSRC}/hello.rb ${RUBY_EXAMPLESDIR}/intl/
	${INSTALL_DATA} ${WRKSRC}/ja.po ${RUBY_EXAMPLESDIR}/intl/po/
	${MKDIR} ${RUBY_DOCDIR}/intl/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/intl/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${RUBY_DOCDIR}/intl/ja/
.endif

.include <bsd.port.mk>
