# New ports collection makefile for:	Make
# Date created:				Wed Jan  3 12:14:41 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Make
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Make
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module implementing 'make' and script

PERL_CONFIGURE=	yes

MAN1=		perlmake.1
MAN3=		Make.3

pre-configure:
	${PERL} -pi -e "s:pmake:perlmake:g" ${WRKSRC}/Makefile.PL
	${CP} ${WRKSRC}/pmake ${WRKSRC}/perlmake

.include <bsd.port.mk>
