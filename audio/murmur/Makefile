# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	murmur
PORTVERSION=	1.2.5
CATEGORIES=	audio net
MASTER_SITES=	SF/mumble/Mumble/${PORTVERSION}
DISTNAME=	mumble-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Murmur is the server component of Mumble

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USERS=		murmur
GROUPS=		murmur
USES=		qmake
USE_QT4=	moc_build corelib network xml sql sql-sqlite3_run

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
LIB_DEPENDS+=	libIce.so:${PORTSDIR}/devel/ice
.else
CONFIG+=	no-ice
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.else
CONFIG+=	no-dbus
.endif

.if ${PORT_OPTIONS:MBONJOUR}
LIB_DEPENDS+=	libdns_sd.so:${PORTSDIR}/net/mDNSResponder
.else
CONFIG+=	no-bonjour
.endif

post-patch:
	@${ECHO_CMD} 'QMAKE_LFLAGS += -fstack-protector' >> ${WRKSRC}/src/murmur/murmur.pro

pre-install:
	@${SED} -i '' -e 's|database=.*|database=/var/db/murmur/murmur.sqlite|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#pidfile=.*|pidfile=/var/run/murmur/murmur.pid|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#logfile=.*|logfile=/var/log/murmur/murmur.log|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#host=.*|host=0.0.0.0|' ${WRKSRC}/scripts/murmur.ini

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/release/murmurd ${STAGEDIR}${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/scripts/murmur.ini ${STAGEDIR}${PREFIX}/etc/murmur.ini.sample
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${CP} ${WRKSRC}/man/murmurd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in CHANGES INSTALL LICENSE README README.Linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
