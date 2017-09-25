# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	murmur
PORTVERSION=	1.2.19
PORTREVISION=	6
CATEGORIES=	audio net

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Murmur is the server component of Mumble

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:devel/boost-libs
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USERS=		murmur
GROUPS=		murmur
USES=		compiler:c++11-lang qmake pkgconfig ssl
USE_QT4=	moc_build corelib network xml sql sql-sqlite3_run

USE_GITHUB=	YES
GH_ACCOUNT=	mumble-voip
GH_PROJECT=	mumble

CONFIG=		no-client
QMAKE_ARGS=	"CONFIG+=${CONFIG}"

USE_RC_SUBR=	murmur
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

OPTIONS_DEFINE=	ICE DBUS BONJOUR DOCS
OPTIONS_DEFAULT=	BONJOUR
ICE_DESC=	Ice Support
BONJOUR_DESC=	Bonjour Support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICE}
LIB_DEPENDS+=	libIce.so:devel/ice
.else
CONFIG+=	no-ice
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.else
CONFIG+=	no-dbus
.endif

.if ${PORT_OPTIONS:MBONJOUR}
LIB_DEPENDS+=	libdns_sd.so:net/mDNSResponder
.else
CONFIG+=	no-bonjour
.endif

.include <bsd.port.pre.mk>
# PCH is broken on GCC
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIG+=	no-pch
.endif

post-patch:
	@${ECHO_CMD} 'QMAKE_LFLAGS += -fstack-protector' >> ${WRKSRC}/src/murmur/murmur.pro

pre-install:
	${SED} -i '' -e 's|database=.*|database=/var/db/murmur/murmur.sqlite|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|#pidfile=.*|pidfile=/var/run/murmur/murmur.pid|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|#logfile=.*|logfile=/var/log/murmur/murmur.log|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|#host=.*|host=0.0.0.0|' ${WRKSRC}/scripts/murmur.ini

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/murmurd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/scripts/murmur.ini ${STAGEDIR}${PREFIX}/etc/murmur.ini.sample
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${CP} ${WRKSRC}/man/murmurd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in CHANGES INSTALL README README.Linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
