# New ports collection makefile for:	p5-Expect
# Date created:		14 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	Expect
PORTVERSION=	1.15
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Expect
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/IO/Tty.pm:${PORTSDIR}/devel/p5-IO-Tty \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Stty.pm:${PORTSDIR}/devel/p5-IO-Stty
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Expect.3

.include <bsd.port.mk>
