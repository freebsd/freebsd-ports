# New ports collection makefile for:	ruby-termios
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	termios
PORTVERSION=	0.9.1
PORTEPOCH=	1
CATEGORIES=	comms ruby
MASTER_SITES=	http://arika.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDTOOL=	yes

INSTALL_TARGET=	site-install

DOCS=		ChangeLog	README		termios.html	termios.rd

post-patch:
	${RUBY} -i -pe 'gsub(/ttyS\d/, "cuaa0")' ${WRKSRC}/examples/*.rb
	${RUBY} -i -pe 'gsub(/\.c_/, ".")' ${WRKSRC}/examples/*.rb

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY_RD2} termios.rd > termios.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
