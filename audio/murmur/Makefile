# New ports collection makefile for:	murmur
# Date created:		2009-08-03
# Whom:			Ayumi M <ayu@commun.jp>
#
# $FreeBSD$
#

PORTNAME=	murmur
PORTVERSION=	1.2.3
CATEGORIES=	audio net
MASTER_SITES=	SF/mumble/Mumble/${PORTVERSION}
DISTNAME=	mumble-${PORTVERSION}

MAINTAINER=	ayu@commun.jp
COMMENT=	Murmur is the server component of Mumble

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	protobuf.6:${PORTSDIR}/devel/protobuf

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build corelib network xml sql sql-sqlite3_run

CONFIG=		no-client

MAN1=		murmurd.1
USE_RC_SUBR=	murmur

OPTIONS=	ICE "Ice Support" on \
		DBUS "D-Bus Support" off \
		BONJOUR "Bonjour Support" on

.include <bsd.port.pre.mk>

.if defined(WITH_ICE)
LIB_DEPENDS+=	Ice.34:${PORTSDIR}/devel/ice
.else
CONFIG+=	no-ice
.endif

.if defined(WITH_DBUS)
QT_COMPONENTS+=	dbus
.else
CONFIG+=	no-dbus
.endif

.if defined(WITH_BONJOUR)
LIB_DEPENDS+=	dns_sd.1:${PORTSDIR}/net/mDNSResponder
.else
CONFIG+=	no-bonjour
.endif

post-patch:
.if ${OSVERSION} < 700000
	@cd ${WRKSRC} && ${PATCH} -sp < ${PATCHDIR}/freebsd6-patch-compiler.pri
.endif
.if ${OSVERSION} >= 800000
	@${ECHO_CMD} 'QMAKE_LFLAGS += -fstack-protector' >> ${WRKSRC}/src/murmur/murmur.pro
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} \
		${QMAKE} -unix PREFIX=${PREFIX} ${QMAKEFLAGS} main.pro "CONFIG+=${CONFIG}"

pre-su-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in CHANGES INSTALL LICENSE README README.Linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
