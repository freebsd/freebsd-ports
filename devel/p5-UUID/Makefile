PORTNAME=	UUID
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JNH
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl extension for using UUID interfaces as defined in e2fsprogs

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USES=		perl5
USE_PERL5=	configure
CFLAGS+=	-I${LOCALBASE}/include

post-build:
	@${RM} /var/run/libuuid/clock.txt /var/run/libuuid/request /var/run/libuuid/uuidd.pid

.include <bsd.port.mk>
