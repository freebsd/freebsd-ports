# New ports collection makefile for:	IO-Pager
# Date created:				Apr 1 2005
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Pager
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/J/JP/JPIERCE
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	rafan@infor.org
COMMENT=	Select a pager, optionally pipe it output if destination is a TTY

PERL_CONFIGURE=	yes

MAN3=		IO::Pager::Buffered.3 \
		IO::Pager::Page.3 \
		IO::Pager::Unbuffered.3 \
		IO::Pager.3

.include <bsd.port.mk>
