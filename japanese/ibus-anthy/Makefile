# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ibus-anthy
PORTVERSION=	1.2.7
PORTREVISION=	6
CATEGORIES=	japanese
PROJECTHOST=	ibus
MASTER_SITES=	https://github.com/ibus/ibus-anthy/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	ja-

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Anthy engine for IBus

BUILD_DEPENDS=	swig:devel/swig13
LIB_DEPENDS=	libanthy.so:japanese/anthy \
		libibus-1.0.so:textproc/ibus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:devel/py-notify

GNU_CONFIGURE=	yes
USES=		libtool gettext gmake pkgconfig python
USE_GNOME=	intltool pygtk2

LOCALBASE_REPLACE_FILES= \
		engine/engine.py \
		setup/anthyprefs.py \
		setup/main.py

INCLUDEDIR_REPLACE_FILES= \
		engine/Makefile.am \
		engine/Makefile.in

post-patch:
	cd ${WRKSRC} && \
                ${REINPLACE_CMD} "s,@@LOCALBASE@@,${LOCALBASE},g" \
                ${LOCALBASE_REPLACE_FILES} && \
                ${REINPLACE_CMD} "s,@@INCLUDEDIR@@,${INCLUDEDIR},g" \
                ${INCLUDEDIR_REPLACE_FILES}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_anthy.so

.include <bsd.port.mk>
