# New ports collection makefile for:	devel/p5-Getopt-Mixed
# Date created:				17 Jan 2003
# Whom:					sumikawa
#
# $FreeBSD$
#

PORTNAME=	Getopt-Mixed
PORTVERSION=	1.008
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Getopt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Getopt::Mixed.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
	${PERL} -pi -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
