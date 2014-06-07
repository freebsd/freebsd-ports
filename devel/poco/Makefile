# Created by: Wes Peters <wes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poco
# New version 1.4.6p4 is available; please use DISTVERSION upon updating
PORTVERSION=	1.4.3
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	wes@FreeBSD.org
COMMENT=	C++ libraries with a network/internet focus

LICENSE=	BSL

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

.include <bsd.port.mk>
