# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	PCSC-Card
PORTVERSION=	1.4.13
CATEGORIES=	devel perl5
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	pcsc-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl bindings for the PC/SC Lite Framework

LIB_DEPENDS=	libpcsclite.so:${PORTSDIR}/devel/pcsc-lite

USES=		perl5 pkgconfig tar:bzip2
USE_PERL5=	configure
MAKE_ENV=	"LOCALBASE=${LOCALBASE}"

post-patch:
	${REINPLACE_CMD} -e "s,-I/usr/local/pcsc/include,${LOCALBASE}/include/PCSC," \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
