# Created by: jmz
# $FreeBSD$

PORTNAME=	ExtUtils-F77
PORTVERSION=	1.23
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helps link C programs with Fortran subroutines

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which

USES=		fortran perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|'gfortran48'|'${FC}'|; s|'-O2'|'${CFLAGS}'|" ${WRKSRC}/F77.pm

.include <bsd.port.mk>
