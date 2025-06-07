PORTNAME=	dbus
DISTVERSION=	1.16.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	https://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Message bus system for inter-application communication
WWW=		https://www.freedesktop.org/Software/dbus

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cpe libtool localbase meson pkgconfig python:build \
		shebangfix tar:xz
CPE_VENDOR=	d-bus_project
CPE_PRODUCT=	d-bus
USE_LDCONFIG=	yes
USE_RC_SUBR=	dbus
SHEBANG_FILES=	tools/GetAllMatchRules.py \
		tools/build-timestamp.py

HAS_SYMBOL_VERSION=	${PREFIX}/lib/libdbus-1.so.${_LIBVERSION}

MESON_ARGS=	-Dkqueue=enabled \
		-Dapparmor=disabled \
		-Ddoxygen_docs=disabled \
		-Dducktype_docs=disabled \
		-Depoll=disabled \
		-Dinotify=disabled \
		-Dlaunchd=disabled \
		-Dlibaudit=disabled \
		-Dmodular_tests=disabled \
		-Dqt_help=disabled \
		-Dselinux=disabled \
		-Dsystemd=disabled \
		-Druntime_dir=/var/run \
		-Dsession_socket_dir=/tmp \
		-Dtest_socket_dir=${WRKDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD}

PORTSCOUT=	limitw:1,even

USERS=		messagebus
GROUPS=		messagebus

_LIBVERSION=	3.38.3

OPTIONS_SUB=	yes
PLIST_SUB=	GROUPS=${GROUPS} \
		VERSION="1.0" \
		LIBVERSION=${_LIBVERSION}
PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES MANPAGES X11
OPTIONS_DEFAULT=	MANPAGES X11

MANPAGES_BUILD_DEPENDS=		docbook-xsl>0:textproc/docbook-xsl
MANPAGES_USES=			gnome
MANPAGES_USE=			gnome=libxslt:build
MANPAGES_MESON_ENABLED=		xml_docs

X11_DESC=		Support X11 Desktop Environments
X11_USES=			xorg
X11_USE=			XORG=ice,sm,x11
X11_MESON_ENABLED=		x11_autolaunch

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/dbus/dbus-sysdeps-util-unix.c

post-install:
	${MV} ${STAGEDIR}${DOCSDIR}/examples ${STAGEDIR}${EXAMPLESDIR}
.for file in session.conf system.conf
	@cd ${STAGEDIR}${ETCDIR}-1/ && \
		${MV} ${file} ${file}.sample
.endfor

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1400000
MESON_ARGS+=	-Db_lundef=false
.endif

.include <bsd.port.post.mk>
