# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool
PORTVERSION=	1.4.9
CATEGORIES=	databases
MASTER_SITES=	http://tarantool.org/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${TR_REV}-src

MAINTAINER=	vg@FreeBSD.org
COMMENT=	High performance key/value storage server

LICENSE=	BSD

TR_REV=		45-g2f7b3f9
USES=		cmake gettext:build
USE_GCC=	4.6+
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
MAN1=		tarantool_box.1
CMAKE_ARGS=	-DCMAKE_MAN_DIR=man/man1

OPTIONS_DEFINE=	CLIENT DEBUG STATIC
CLIENT_DESC=	Enable client
DEBUG_DESC=	Enable debug
STATIC_DESC=	Enable static (got core dump)

OPTIONS_DEFAULT=CLIENT DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
CMAKE_ARGS+=	-DENABLE_CLIENT=true
CFLAGS+=	"-O0 -g"
PLIST_SUB+=	CLIENT=""
MAN1+=		tarantool.1
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebugInfo
.endif

.if ${PORT_OPTIONS:MSTATIC}
LIB_DEPENDS+=	iconv:${PORTSDIR}/converters/iconv
CMAKE_ARGS+=	-DENABLE_STATIC=true
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
