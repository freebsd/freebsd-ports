# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	murmur
PORTVERSION=	1.2.4
CATEGORIES=	audio net
MASTER_SITES=	SF/mumble/Mumble/${PORTVERSION}
DISTNAME=	mumble-${PORTVERSION}

MAINTAINER=	ayu@commun.jp
COMMENT=	Murmur is the server component of Mumble

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	protobuf:${PORTSDIR}/devel/protobuf

USERS=		${PORTNAME}
NO_STAGE=	yes
GROUPS=		${USERS}
USE_QT4=	qmake_build moc_build corelib network xml sql sql-sqlite3_run

CONFIG=		no-client

MAN1=		murmurd.1
USE_RC_SUBR=	murmur

OPTIONS_DEFINE=	ICE DBUS BONJOUR DOCS
OPTIONS_DEFAULT=	ICE BONJOUR
ICE_DESC=	Ice Support
BONJOUR_DESC=	Bonjour Support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICE}
LIB_DEPENDS+=	Ice:${PORTSDIR}/devel/ice
.else
CONFIG+=	no-ice
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.else
CONFIG+=	no-dbus
.endif

.if ${PORT_OPTIONS:MBONJOUR}
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
.else
CONFIG+=	no-bonjour
.endif

post-patch:
.if ${OSVERSION} >= 800000
	@${ECHO_CMD} 'QMAKE_LFLAGS += -fstack-protector' >> ${WRKSRC}/src/murmur/murmur.pro
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} \
		${QMAKE} -unix PREFIX=${PREFIX} ${QMAKEFLAGS} main.pro "CONFIG+=${CONFIG}"

pre-install:
	@${SED} -i '' -e 's|database=.*|database=/var/db/murmur/murmur.sqlite|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#pidfile=.*|pidfile=/var/run/murmur/murmur.pid|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#logfile=.*|logfile=/var/log/murmur/murmur.log|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#host=.*|host=0.0.0.0|' ${WRKSRC}/scripts/murmur.ini

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/release/murmurd ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/scripts/murmur.ini ${PREFIX}/etc/murmur.ini.sample
	@if [ ! -f ${PREFIX}/etc/murmur.ini ]; then \
		${CP} -p ${PREFIX}/etc/murmur.ini.sample ${PREFIX}/etc/murmur.ini; \
	fi
	${INSTALL_MAN} ${WRKSRC}/man/murmurd.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in CHANGES INSTALL LICENSE README README.Linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
