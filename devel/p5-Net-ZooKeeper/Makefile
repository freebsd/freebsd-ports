# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-ZooKeeper
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension for Apache ZooKeeper

LIB_DEPENDS=	libzookeeper_mt.so:${PORTSDIR}/devel/libzookeeper

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=	--zookeeper-include ${PREFIX}/include/zookeeper \
			--zookeeper-lib ${PREFIX}/libs

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Net/ZooKeeper/ZooKeeper.so

.include <bsd.port.mk>
