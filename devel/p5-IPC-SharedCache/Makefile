# New ports collection makefile for:	p5-IPC-SharedCache
# Date created:				2001/08/29
# Whom:	      				nork@cityfujisawa.ne.jp
#
# $FreeBSD$
#

PORTNAME=	IPC-SharedCache
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/IPC/ShareLite.pm:${PORTSDIR}/devel/p5-IPC-ShareLite \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable

RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IPC::SharedCache.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
