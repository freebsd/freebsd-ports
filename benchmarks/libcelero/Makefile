# $FreeBSD$

PORTNAME=	libcelero
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ benchmark authoring library/framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo

USES=		cmake:outsource compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	DigitalInBlue
GH_PROJECT=	Celero
USE_LDCONFIG=	yes

.include <bsd.port.mk>
