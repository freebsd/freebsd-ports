# New ports collection makefile for:	Ruby-sysvipc
# Date created:		12 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sysvipc
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://deisui.bug.org/~ueno/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby interface to use System V IPC system calls

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_RD_FILES=	sysvipc.rd

INSTALL_TARGET=	site-install

DOCS=		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}

.include <bsd.port.pre.mk>

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
