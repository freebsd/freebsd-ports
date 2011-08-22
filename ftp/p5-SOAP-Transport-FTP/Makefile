# New ports collection makefile for:	p5-SOAP-Transport-FTP
# Date created:		2011-08-20
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SOAP-Transport-FTP
PORTVERSION=	0.711
CATEGORIES=	ftp net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	FTP Client support for SOAP::Lite

BUILD_DEPENDS=	p5-SOAP-Lite>=0.711:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	p5-SOAP-Lite>=0.711:${PORTSDIR}/net/p5-SOAP-Lite

PERL_CONFIGURE=	yes

MAN3=		SOAP::Transport::FTP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Module-Build>=0.3600:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
