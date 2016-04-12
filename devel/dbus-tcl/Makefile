# Created by: gahr
# $FreeBSD$

PORTNAME=	dbus-tcl
PORTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/dbus/${PORTVERSION}/
DISTNAME=	dbus-${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl interface to the D-Bus messaging system

LICENSE=	ISCL

LIB_DEPENDS=	libdbus-1.so:devel/dbus
BUILD_DEPENDS=	dtplite:devel/tcllib

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/dbus
PORTDOCS=	*

TEST_TARGET=	do-test

USES=		pkgconfig tcl:85+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

PLIST_FILES=	lib/dbus/libdbus21.so.1 \
		lib/dbus/pkgIndex.tcl \
		man/mann/dbus.n.gz

post-patch:
	${REINPLACE_CMD} -e '/^INSTALL_PROGRAM/s|$$| -s|' \
	    ${WRKSRC}/Makefile.in

do-test:
	DBUS=$$(${LOCALBASE}/bin/dbus-daemon --session --print-address --fork --print-pid); \
	DBUS_ADDR=$$(echo $$DBUS | awk '{print $$1}'); \
	DBUS_PID=$$(echo $$DBUS | awk '{print $$2}'); \
	DBUS_ENV=DBUS_SESSION_BUS_ADDRESS=$$DBUS_ADDR; \
	${SETENV} ${MAKE_ENV} $$DBUS_ENV ${MAKE} -C ${WRKSRC} test; \
	kill $$DBUS_PID

.include <bsd.port.mk>
