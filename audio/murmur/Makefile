# New ports collection makefile for:	murmur
# Date created:		2009-08-03
# Whom:			Ayumi M <ayu@commun.jp>
#
# $FreeBSD$
#

PORTNAME=	murmur
PORTVERSION=	1.1.8
CATEGORIES=	audio net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	mumble
DISTNAME=	mumble-${PORTVERSION}

MAINTAINER=	ayu@commun.jp
COMMENT=	Murmur is the server component of Mumble

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlite.so:${PORTSDIR}/databases/qt4-sqlite3-plugin

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build corelib network xml sql
HAS_CONFIGURE=	yes

CONFIG=		no-client

MAN1=		murmurd.1
USE_RC_SUBR=	murmur

OPTIONS=	ICE "Ice Support" on \
		DBUS "D-Bus Support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ICE)
LIB_DEPENDS+=	Ice.33:${PORTSDIR}/devel/ice
.else
CONFIG+=	no-ice
.endif

.if defined(WITH_DBUS)
QT_COMPONENTS+=	dbus
.else
CONFIG+=	no-dbus
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} \
		${QMAKE} -unix PREFIX=${PREFIX} main.pro "CONFIG+=${CONFIG}"

pre-su-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

pre-install:
	@${SED} -i '' -e 's|database=.*|database=/var/db/murmur/murmur.sqlite|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#pidfile=.*|pidfile=/var/run/murmur/murmur.pid|' ${WRKSRC}/scripts/murmur.ini
	@${SED} -i '' -e 's|#logfile=.*|logfile=/var/log/murmur/murmur.log|' ${WRKSRC}/scripts/murmur.ini

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/release/murmurd ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/scripts/murmur.ini ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/man/murmurd.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in CHANGES INSTALL LICENSE README README.Linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
