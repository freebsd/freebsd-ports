# New ports collection makefile for:	p5-File-Fetch
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Fetch
PORTVERSION=	0.20
CATEGORIES=	ftp www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic file fetching mechanism

RUN_DEPENDS=	p5-IPC-Cmd>=0.42:${PORTSDIR}/devel/p5-IPC-Cmd
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Fetch.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Load-Conditional>=0.04:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Params-Check>=0.07:${PORTSDIR}/devel/p5-Params-Check
.endif

.include <bsd.port.post.mk>
