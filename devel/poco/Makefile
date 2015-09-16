# Created by: Wes Peters <wes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poco
DISTVERSION=	1.6.0
CATEGORIES=	devel net
MASTER_SITES=	http://pocoproject.org/releases/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	wes@FreeBSD.org
COMMENT=	C++ libraries with a network/internet focus

LICENSE=	BSL

BROKEN_FreeBSD_9_i386=	does not build

CONFLICTS=	poco-ssl-[0-9]*

USES=		gmake tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --config=FreeBSD
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	TEST SAMPLES
SAMPLES_DESC=	Build sample programs

TEST_CONFIGURE_OFF=	--no-tests
SAMPLES_CONFIGURE_OFF=	--no-samples

post-patch:
	@${REINPLACE_CMD} -e 's/ =/ ?=/' ${WRKSRC}/build/config/FreeBSD

post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/include/Poco/._Version.h

.include <bsd.port.mk>
