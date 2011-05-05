# New ports collection makefile for:	p5-ExtUtils-F77
# Date created:				December 7 1999
# Whom:	      				jmz
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-F77
PORTVERSION=	1.17
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helps link C programs with Fortran subroutines

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::F77.3

GCCLIBDIR_CMDS=	${FC} -print-file-name=libgfortran.so | ${SED} -e s/libgfortran.so//
F2CLIB=		-lgfortran

post-patch:
	@${REINPLACE_CMD} -e "s/'gfortran44'/'${FC}'/" \
			  -e "s/'-O2'/'${CFLAGS}'/" \
			  ${WRKSRC}/F77.pm

.include <bsd.port.mk>
