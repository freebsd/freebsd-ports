# New ports collection makefile for:	p5-IPC-Shareable
# Date created:				May 25th 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	IPC-Shareable
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Storable.pm:${PORTSDIR}/devel/p5-Storable

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		IPC::Shareable.3 IPC::Shareable::SharedMem.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
