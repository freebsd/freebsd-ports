# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	1.8.20
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Message bus system for inter-application communication

LIB_DEPENDS=	libexpat.so:textproc/expat2

PORTSCOUT=	limitw:1,even

USE_GNOME=	# empty but we need it for USE_GNOME_SUBR
USES=		cpe gmake libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=--localstatedir=/var \
	        --with-test-socket-dir=${WRKDIR} \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/system_bus_socket \
		--with-session-socket-dir=/tmp \
		--disable-doxygen-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

CPE_VENDOR=	d-bus_project
CPE_PRODUCT=	d-bus

USE_RC_SUBR=	dbus
USE_GNOME_SUBR=	yes

USERS=		messagebus
GROUPS=		messagebus

PLIST_SUB=	VERSION="1.0" GROUPS=${GROUPS}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	MANPAGES X11
OPTIONS_DEFAULT=MANPAGES X11
X11_DESC=	Support X11 Desktop Environments

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto
MANPAGES_CONFIGURE_ENABLE=	xml-docs
X11_USE=	xorg=ice,sm,x11
X11_CONFIGURE_WITH=	x

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/dbus/dbus-sysdeps-unix.c
	@${REINPLACE_CMD} -e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/doc/dbus-uuidgen.1.xml.in \
		${WRKSRC}/dbus/Makefile.in \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ s|test||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|THREAD_LIBS -lrt|THREAD_LIBS|g ; \
		s|dummy man2html|dummy man2html_disable|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|install-data-am: install-data-local|install-data-am:|g' \
		${WRKSRC}/tools/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/interfaces
	@${MKDIR} ${STAGEDIR}/var/run/dbus
	@${MKDIR} ${STAGEDIR}/var/db/dbus

.include <bsd.port.mk>
