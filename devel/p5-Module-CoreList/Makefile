# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	Module-CoreList
PORTVERSION=	5.20160429
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	See what modules shipped with versions of Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
