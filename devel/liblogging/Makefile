PORTNAME=	liblogging
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
CATEGORIES=	devel

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Easy to use system logging library
WWW=		https://www.liblogging.org/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}

USES=		autoreconf cpe libtool pathfix pkgconfig python:env

PORTSCOUT=	limit:^1\.

USE_GITHUB=	yes
GH_ACCOUNT=	rsyslog

CPE_VENDOR=	adiscon

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=		--disable-journal --enable-rfc3195
USE_LDCONFIG=			yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-rfc3195.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-stdlog.so.0.1.0

.include <bsd.port.mk>
