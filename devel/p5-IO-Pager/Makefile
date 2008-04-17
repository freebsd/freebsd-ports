# New ports collection makefile for:	IO-Pager
# Date created:				Apr 1 2005
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Pager
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Select a pager, optionally pipe it output if destination is a TTY

PERL_CONFIGURE=	yes

MAN3=		IO::Pager::Buffered.3 \
		IO::Pager::Page.3 \
		IO::Pager::Unbuffered.3 \
		IO::Pager.3

post-patch:
	@${RM} ${WRKSRC}/lib/IO/Pager.pm~

.include <bsd.port.mk>
