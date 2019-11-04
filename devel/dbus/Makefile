# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	1.12.12
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Message bus system for inter-application communication

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:textproc/expat2

PORTSCOUT=	limitw:1,even

USES=		cpe gmake libtool localbase pkgconfig python:build shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-test-socket-dir=${WRKDIR} \
		--disable-doxygen-docs \
		--disable-selinux \
		--disable-apparmor \
		--disable-systemd
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	tools/GetAllMatchRules.py

CPE_VENDOR=	d-bus_project
CPE_PRODUCT=	d-bus

USE_RC_SUBR=	dbus

USERS=		messagebus
GROUPS=		messagebus

PLIST_SUB=	VERSION="1.0" GROUPS=${GROUPS}

OPTIONS_DEFINE=	EXAMPLES MANPAGES X11
OPTIONS_DEFAULT=MANPAGES X11
OPTIONS_SUB=	yes
X11_DESC=	Support X11 Desktop Environments

MANPAGES_CONFIGURE_ENV=	XMLTO=${LOCALBASE}/bin/minixmlto
MANPAGES_BUILD_DEPENDS=	minixmlto:textproc/minixmlto
MANPAGES_CONFIGURE_ENABLE=	xml-docs
X11_USES=	xorg
X11_USE=	xorg=ice,sm,x11
X11_CONFIGURE_WITH=	x

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/dbus/dbus-sysdeps-unix.c
	@${REINPLACE_CMD} '/^SUBDIRS =/s|test||' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RM} -r ${STAGEDIR}${DOCSDIR}
.for file in session.conf system.conf
	@cd ${STAGEDIR}${ETCDIR}-1/ && \
		${MV} ${file} ${file}.sample
.endfor

.include <bsd.port.mk>
