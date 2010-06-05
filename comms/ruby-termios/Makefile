# New ports collection makefile for:	ruby-termios
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	termios
PORTVERSION=	0.9.5
PORTEPOCH=	1
CATEGORIES=	comms ruby
MASTER_SITES=	http://arika.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby interface to termios

MAKE_JOBS_UNSAFE=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	termios.rd

DOCS=		ChangeLog	README \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}

.include <bsd.port.pre.mk>

post-patch:
	${RUBY} -i -pe 'gsub(/ttyS\d/, "cuaa0")' ${WRKSRC}/examples/*.rb
	${RUBY} -i -pe 'gsub(/\.c_/, ".")' ${WRKSRC}/examples/*.rb

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
