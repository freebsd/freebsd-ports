# New ports collection makefile for:	Gem Finder
# Date created:		12 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gemfinder
PORTVERSION=	1.8
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.one.net/pub/users/jweirich/tools/gemfinder/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_LIBDIR}/tk.rb:${PORTSDIR}/x11-toolkits/ruby-tk

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/gemfinder

DOCS=		README		gemfinder.html	gemfinder.rd

do-build:
.if !defined(NOPORTDOCS)
	${RUBY_RD2} < ${WRKSRC}/gemfinder.rd \
		| ${SED} -e 's/<BODY>/<body bgcolor="#ffffff">/' \
		> ${WRKSRC}/gemfinder.html
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gemfinder ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
