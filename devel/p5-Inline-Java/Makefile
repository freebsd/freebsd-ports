# ex:ts=8
# Ports collection makefile for:	Inline::Java
# Date created:			Aug 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Inline-Java
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Inline
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Inline.pm:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Inline::Java.3

.include <bsd.port.mk>
