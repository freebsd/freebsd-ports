# New ports collection makefile for:	p5-IPC-Shareable
# Date created:				May 25th 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	IPC-Shareable
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Share Perl variables between processes

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable

PERL_CONFIGURE=	yes

MAN3=		IPC::Shareable.3 IPC::Shareable::SharedMem.3

.include <bsd.port.mk>
