# New ports collection makefile for:	p5-Time-HiRes
# Date created:			13 June 1999
# Whom:				Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	Time-HiRes
PORTVERSION=	1.38
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Time::HiRes.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${PERL} -pi -e '$$_ = "" if /MAN3PODS|INSTALLDIRS/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
