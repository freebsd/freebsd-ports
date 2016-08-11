# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	telldus-core
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://download.telldus.se/TellStick/Software/telldus-core/

MAINTAINER=	johan@stromnet.se
COMMENT=	Tellstick Telldus daemon + library

LICENSE=	LGPL21

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libftdi.so:devel/libftdi \
		libconfuse.so:devel/libconfuse \
		libargp.so:devel/argp-standalone

USES= 		cmake compiler:c++11-lang iconv:wchar_t

#CMAKE_VERBOSE=yes
CMAKE_ARGS+=-DGENERATE_MAN=TRUE
# Note: these are internal defines and shall NOT contain ${STAGEDIR}
CMAKE_ARGS+=-DSYSCONF_INSTALL_DIR="${PREFIX}/etc"
CMAKE_ARGS+=-DSTATE_INSTALL_DIR="/var/telldus"

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	telldusd
USER=		nobody
GROUP=		dialer

.include <bsd.port.pre.mk>

post-patch:
# remove tr1 if using libc++
.if ${COMPILER_FEATURES:Mlibc++}
	@${REINPLACE_CMD} -e 's|tr1::||' ${WRKSRC}/common/Event.h
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/etc && \
		 ${MV} tellstick.conf tellstick.conf.sample
	${RM} ${STAGEDIR}/var/telldus/telldus-core.conf

.include <bsd.port.post.mk>
