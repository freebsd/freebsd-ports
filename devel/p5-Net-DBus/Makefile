PORTNAME=	Net-DBus
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl extension for the DBus message system
WWW=		https://metacpan.org/release/Net-DBus

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	p5-XML-Twig>=0:textproc/p5-XML-Twig

USES=		perl5 pkgconfig
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/DBus/DBus.so

.include <bsd.port.mk>
