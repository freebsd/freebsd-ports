# New ports collection makefile for:	ruby-termios
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	termios
PORTVERSION=	20001115
PORTREVISION=	1
CATEGORIES=	comms ruby
MASTER_SITES=	http://arika.org/pub/Tools/Ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

post-patch:
	${RUBY} -i -pe 'gsub /ttyS\d/, "cuaa0"' ${WRKSRC}/test/*.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/test/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
