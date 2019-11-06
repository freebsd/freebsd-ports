# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	telldus-core
PORTVERSION=	2.1.2
PORTREVISION=	7
CATEGORIES=	comms
MASTER_SITES=	http://download.telldus.se/TellStick/Software/telldus-core/

MAINTAINER=	johan@stromnet.se
COMMENT=	Tellstick Telldus daemon + library

BROKEN=		unfetchable

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libftdi.so:devel/libftdi \
		libconfuse.so:devel/libconfuse \
		libargp.so:devel/argp-standalone

USES=		cmake compiler:c++11-lang iconv:wchar_t
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DGENERATE_MAN=TRUE
# Note: these are internal defines and shall NOT contain ${STAGEDIR}
CMAKE_ARGS+=	-DSYSCONF_INSTALL_DIR="${PREFIX}/etc"
# Using global /var, otherwise testport complains "Warning: port uses /usr/local/var instead of /var"
CMAKE_ARGS+=	-DSTATE_INSTALL_DIR="/var/telldus"
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	telldusd
USER=		nobody
GROUP=		dialer

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
# remove tr1 if using libc++
.if ${COMPILER_FEATURES:Mlibc++}
	@${REINPLACE_CMD} -e 's|tr1::||' ${WRKSRC}/common/Event.h
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/etc && \
		${MV} tellstick.conf tellstick.conf.sample
	# This file is actually empty but allows us to simply use @sample to
	# make sure it stays between upgrades if modified
	cd ${STAGEDIR}/var/telldus && \
		${MV} telldus-core.conf telldus-core.conf.sample

.include <bsd.port.post.mk>
