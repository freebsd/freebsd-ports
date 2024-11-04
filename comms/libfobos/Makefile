PORTNAME=	libfobos
DISTVERSIONPREFIX=	v.
DISTVERSION=	2.3.1
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	RigExpert Fobos SDR API
WWW=		https://github.com/AlexandreRouma/SDRPlusPlus

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake dos2unix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rigexpert

DOS2UNIX=	fobos/fobos.c

LDFLAGS+=	-lusb

PLIST_FILES=	include/fobos.h \
		lib/libfobos.so \
		libdata/pkgconfig/libfobos.pc

post-install:
	${RM} -r ${STAGEDIR}/etc

.include <bsd.port.mk>
