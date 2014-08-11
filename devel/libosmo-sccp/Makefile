# $FreeBSD$

PORTNAME=	libosmo-sccp
PORTVERSION=	0.0.6.3
CATEGORIES=	devel
MASTER_SITES=   http://chaosophia.net/downloads/osmocom/${PORTNAME}/ \
		http://ns1.chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	SCCP network layer protocol implementation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libosmocore.so:${PORTSDIR}/devel/libosmocore

USES=		gmake pkgconfig

USE_AUTOTOOLS=	aclocal autoconf automake libtoolize
AUTOMAKE_ARGS=	--gnu --add-missing --copy

post-patch:
	${REINPLACE_CMD} -e 's|pkgconfigdir.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
