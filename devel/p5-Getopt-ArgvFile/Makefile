# New ports collection makefile for:	devel/p5-Getopt-ArgvFile
# Date created:				03 May 2002
# Whom:					Eric Schnoebelen <eric@cirr.com>
#
# $FreeBSD$
#

PORTNAME=	Getopt-ArgvFile
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Getopt
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@cirr.com

PERL_CONFIGURE=	yes

MAN3=		Getopt::ArgvFile.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
	${PERL} -pi -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
