# New ports collection makefile for:	Ruby/Gyokuro
# Date created:		5 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gyokuro
PORTVERSION=	1.0.0
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	http://downloads.sourceforge.jp/gyokuro/1017/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/chasen.so:${PORTSDIR}/japanese/ruby-chasen

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_JA=	README.ja.rd

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/gyokuro
	${INSTALL_DATA} ${WRKSRC}/lib/gyokuro/*.rb ${RUBY_SITELIBDIR}/gyokuro/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
