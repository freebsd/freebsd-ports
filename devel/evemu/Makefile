# Created by: Vladimir Kondratyev <wulf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evemu
PORTVERSION=	2.6.0
CATEGORIES=     devel
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Records and replays EVDEV descriptions and events

LICENSE=	GPLv3

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:devel/libevdev

USES=		tar:xz python:2,build pathfix libtool pkgconfig localbase

OPTIONS_DEFINE=	MANPAGES PYTHON
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=		minixmlto:textproc/minixmlto \
				asciidoc:textproc/asciidoc
MANPAGES_CONFIGURE_ENV=		XMLTO=${LOCALBASE}/bin/minixmlto
MANPAGES_CONFIGURE_ENV_OFF=	ac_cv_path_XMLTO="" \
				ac_cv_path_ASCIIDOC=""
PYTHON_RUN_DEPENDS=		${PYTHON_CMD}:${PYTHON_PORTSDIR}
PYTHON_CONFIGURE_ENABLE=	python-bindings

GNU_CONFIGURE=  yes
CFLAGS+=	-D_WITH_DPRINTF -include stdlib.h
USE_LDCONFIG=   yes
INSTALL_TARGET=	install-strip
REINPLACE_ARGS=	-i ''

TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/test

post-patch:
	${REINPLACE_CMD} -e 's|program_invocation_short_name|getprogname()|' \
		${WRKSRC}/tools/evemu-event.c ${WRKSRC}/tools/evemu-play.c \
		${WRKSRC}/tools/evemu-record.c
	${REINPLACE_CMD} -e 's|versionsort|alphasort|' \
		${WRKSRC}/tools/find_event_devices.c

# Fix evemu-event.1, evemu-play.1 and evemu-record.1 manpages which are broken
# due to docbook-xsl bug: https://sourceforge.net/p/docbook/bugs/1058/
post-install-MANPAGES-on:
.for manpage in evemu-event.1 evemu-play.1 evemu-record.1
	@${REINPLACE_CMD} -e 's|^\.so evemu|.so man1/evemu|' \
		${STAGEDIR}${MANPREFIX}/man/man1/${manpage}
.endfor

.include <bsd.port.mk>
