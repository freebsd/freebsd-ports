# Created by: jmz
# $FreeBSD$

PORTNAME=	ExtUtils-F77
PORTVERSION=	1.20
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helps link C programs with Fortran subroutines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

NO_ARCH=	yes
USES=		fortran perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e "s|'gfortran44'|'${FC}'|" \
			  -e "s|'-O2'|'${CFLAGS}'|" \
			  ${WRKSRC}/F77.pm

.include <bsd.port.mk>
