# New ports collection makefile for:	p5-Data-Uniqid
# Date created:		2008-11-28
# Whom:			Sergey V. Dyatko <sergey.dyatko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Data-Uniqid
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Perl extension for simple genrating of unique id's

PERL_CONFIGURE=	yes

MAN3=		Data::Uniqid.3

PORTDOCS=	Changes README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
