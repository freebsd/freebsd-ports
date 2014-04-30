# Created by: jasone
# $FreeBSD$

PORTNAME=	onyx
PORTVERSION=	5.1.2
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/

MAINTAINER=	jasone@FreeBSD.org
COMMENT=	Embeddable stack-based threaded interpreted language

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook
LIB_DEPENDS=	libedit.so:${PORTSDIR}/devel/libedit \
		libpcre.so:${PORTSDIR}/devel/pcre

USES=		desthack tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libedit-prefix=${LOCALBASE} \
		--with-pcre-prefix=${LOCALBASE}
USE_LDCONFIG=	yes

PLIST_SUB=	ONYX_VERSION=${PORTVERSION}

BROKEN_ia64=	Coredump during build on ia64

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} cook install)
	@${STRIP_CMD} ${PREFIX}/bin/onyx

.include <bsd.port.mk>
