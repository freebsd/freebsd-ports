# New ports collection makefile for:	devel/p5-Getopt-Mixed
# Date created:				17 Jan 2003
# Whom:					sumikawa
#
# $FreeBSD$
#

PORTNAME=	Getopt-Mixed
PORTVERSION=	1.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for processing of both short and long command line options

DEPRECATED=	Use devel/p5-Getopt-Long instead
EXPIRATION_DATE=	2007-04-23

PERL_CONFIGURE=	yes

MAN3=		Getopt::Mixed.3

pre-configure:
	${PERL} -pi -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
