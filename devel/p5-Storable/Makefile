# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Storable
PORTVERSION=	2.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Persistency for perl data structures

PERL_CONFIGURE=	yes

MAN3=		Storable.3

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|INSTALLDIRS|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
