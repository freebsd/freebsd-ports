PORTNAME=	libpdel
PORTVERSION=	0.6.1
CATEGORIES=	devel net www
MASTER_SITES=	SF/libpdel/libpdel-combined/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet Design multi-purpose C library for embedded applications

LICENSE=	PACKETDESIGN
LICENSE_NAME=	Packet Design
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		tar:bz2
USE_LDCONFIG=	yes

MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

WRKSRC_SUBDIR=	pdel

.include <bsd.port.mk>
