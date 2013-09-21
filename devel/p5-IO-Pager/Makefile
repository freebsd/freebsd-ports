# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	IO-Pager
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Select a pager, optionally pipe it output if destination is a TTY

USES=		perl5
USE_PERL5=	configure

MAN3=		IO::Pager::Buffered.3 \
		IO::Pager::Page.3 \
		IO::Pager::Unbuffered.3 \
		IO::Pager.3

NO_STAGE=	yes

regression-test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
