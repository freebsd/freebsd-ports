# New ports collection makefile for:	Ruby-Racc
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	racc
PORTVERSION=	1.4.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-all
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

.if !defined(RUNTIME)
RUN_DEPENDS=	${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime \
		${RUBY_SITELIBDIR}/strscan.rb:${PORTSDIR}/devel/ruby-strscan
.endif

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

.if defined(RUNTIME)
CONFIGURE_ARGS=	--with=raccrt
.else
CONFIGURE_ARGS=	--with=racc

WRKDIR_RACC=	${WRKSRC}/packages/racc

post-extract:
	${CP} -p ${WRKDIR_RACC}/misc/* ${WRKDIR_RACC}/bin/

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR_RACC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${INSTALL_DATA} ${WRKDIR_RACC}/doc.en/* ${RUBY_DOCDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKDIR_RACC}/doc.ja/* ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endif
.endif

.include <bsd.port.mk>
