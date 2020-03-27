# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbus
DISTVERSION=	1.12.16
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Message bus system for inter-application communication

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cpe gmake libtool localbase pkgconfig python:build shebangfix
CPE_VENDOR=	d-bus_project
CPE_PRODUCT=	d-bus
USE_LDCONFIG=	yes
USE_RC_SUBR=	dbus
SHEBANG_FILES=	tools/GetAllMatchRules.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-apparmor \
		--disable-doxygen-docs \
		--disable-selinux \
		--disable-systemd \
		--with-test-socket-dir=${WRKDIR}

INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

USERS=		messagebus
GROUPS=		messagebus

PLIST_SUB=	GROUPS=${GROUPS} \
		VERSION="1.0"

OPTIONS_DEFINE=		EXAMPLES MANPAGES X11
OPTIONS_DEFAULT=	MANPAGES X11
OPTIONS_SUB=		yes
X11_DESC=		Support X11 Desktop Environments

MANPAGES_BUILD_DEPENDS=		minixmlto:textproc/minixmlto
MANPAGES_CONFIGURE_ENABLE=	xml-docs
MANPAGES_CONFIGURE_ENV=		XMLTO=${LOCALBASE}/bin/minixmlto
X11_USES=			xorg
X11_USE=			XORG=ice,sm,x11
X11_CONFIGURE_WITH=		x

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/dbus/dbus-sysdeps-unix.c

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RM} -r ${STAGEDIR}${DOCSDIR}
.for file in session.conf system.conf
	@cd ${STAGEDIR}${ETCDIR}-1/ && \
		${MV} ${file} ${file}.sample
.endfor

.include <bsd.port.mk>
