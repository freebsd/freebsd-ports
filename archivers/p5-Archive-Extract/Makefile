# New ports collection makefile for:	p5-Archive-Extract
# Date created:				28 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Archive-Extract
PORTVERSION=	0.40
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic archive extracting mechanism

BUILD_DEPENDS=	${RUN_DEPENDS}

MAKE_JOBS_SAFE=	yes

MAN3=	Archive::Extract.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-IPC-Cmd>=0.42:${PORTSDIR}/devel/p5-IPC-Cmd
.endif

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Load-Conditional>=0.04:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Params-Check>=0.07:${PORTSDIR}/devel/p5-Params-Check
.endif

.include <bsd.port.post.mk>
