# New ports collection makefile for:	ibus-anthy
# Date created:				30 Apr 2009
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-anthy
PORTVERSION=	1.2.7
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	japanese
PROJECTHOST=	ibus
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	ja-

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Anthy engine for IBus

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy \
		ibus-1.0.401:${PORTSDIR}/textproc/ibus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2

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
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
