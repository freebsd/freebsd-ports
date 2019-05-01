# Created by: Jeremy Messenger <mezz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-tweaks
PORTVERSION=	3.28.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GNOME3

LICENSE=	GPLv3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gnome-shell>=3.28:x11/gnome-shell

PORTSCOUT=	limitw:1,even

NO_ARCH=	yes
USES=		gettext gnome localbase meson pkgconfig \
		python:3.4+ shebangfix tar:xz
USE_GNOME=	gtk30 pygobject3 nautilus3
INSTALLS_ICONS=	yes
SHEBANG_FILES=	gnome-tweaks \
		gnome-tweak-tool-lid-inhibitor \
		meson-postinstall.py

# generates .py[co] files for installed modules
# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
# with these files when module is imported from root user
post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name \*.pyc -delete
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
