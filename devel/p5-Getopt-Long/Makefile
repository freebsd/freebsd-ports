# New ports collection makefile for:	devel/p5-Getopt-Long
# Date created:				31 May 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Long
PORTVERSION=	2.32
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Getopt
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Getopt::Long.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
	${PERL} -pi -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
