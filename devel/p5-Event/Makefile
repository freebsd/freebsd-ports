# New ports collection makefile for:	Event
# Date created:		29 Apr 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Event
PORTVERSION=	0.84
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Event
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

PLIST_SUB=	DOCSDIR="share/doc/${PORTNAME}"
PERL_CONFIGURE=	yes
DOCS=		Tutorial.pdf

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Event.3 Event::MakeMaker.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
