# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ibus-anthy
PORTVERSION=	1.2.7
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	japanese
PROJECTHOST=	ibus
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	ja-

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Anthy engine for IBus

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libanthy.so:${PORTSDIR}/japanese/anthy \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify

GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig
USE_PYTHON=	yes
USE_GNOME=	pygtk2

LOCALBASE_REPLACE_FILES= \
		engine/engine.py \
		setup/anthyprefs.py \
		setup/main.py

INCLUDEDIR_REPLACE_FILES= \
		engine/Makefile.am \
		engine/Makefile.in

NO_STAGE=	yes
post-patch:
	cd ${WRKSRC} && \
                ${REINPLACE_CMD} "s,@@LOCALBASE@@,${LOCALBASE},g" \
                ${LOCALBASE_REPLACE_FILES} && \
                ${REINPLACE_CMD} "s,@@INCLUDEDIR@@,${INCLUDEDIR},g" \
                ${INCLUDEDIR_REPLACE_FILES}

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
