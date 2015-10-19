# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Bidi
PORTVERSION=	2.10
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the libfribidi

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		swig3.0:${PORTSDIR}/devel/swig30
LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi

USE_PERL5=	configure
USES=		perl5

pre-build:
	${LOCALBASE}/bin/swig3.0 -perl -Wall -I${LOCALBASE}/include/fribidi -o ${WRKSRC}/private.c -outdir ${WRKSRC}/lib/Text/Bidi/ ${WRKSRC}/swig/fribidi.i

post-build:
	${INSTALL_DATA} ${WRKSRC}/lib/Text/Bidi/private.pm ${WRKSRC}/blib/lib/Text/Bidi/private.pm

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/Bidi/private/private.so

.include <bsd.port.mk>
