# New ports collection makefile for:	p5-Glade-Perl
# Date created:				07-Jun-2001
# Whom:					marcus
#
# $FreeBSD$
#

PORTNAME=	Glade-Perl
PORTVERSION=	0.57
CATEGORIES=	devel perl5 gnome
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Glade
PKGNAMEPREFIX=	p5-

MAINTAINER=	marcus@marcuscom.com

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome
RUN_DEPENDS=	${BUILD_DEPENDS} \
		glade:${PORTSDIR}/devel/glade

USE_GNOME=	yes
PERL_CONFIGURE=	yes

MAN3PREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=		Glade::PerlGenerate.3

.include <bsd.port.mk>
