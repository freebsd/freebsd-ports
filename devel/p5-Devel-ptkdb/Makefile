# New ports collection makefile for:	p5-Devel-ptkdb
# Date created:				May 9th 2002
# Whom:					Alex Kapranoff <kappa@freebsd.org.ua>
#
# $FreeBSD$
#

PORTNAME=	Devel-ptkdb
PORTVERSION=	1.1074
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Devel::ptkdb.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	@${PERL} -pi -e 's|\bperl\b|site| if $$. == 5;' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
