PORTNAME=	gnome-tweaks
PORTVERSION=	40.10
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GNOME3

LICENSE=	CC0-1.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy
RUN_DEPENDS=	gnome-shell>=3.28:x11/gnome-shell \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		gettext gnome localbase meson pkgconfig python:3.4+ shebangfix \
		tar:xz
USE_GNOME=	gtk30 nautilus3 pygobject3
GLIB_SCHEMAS=	org.gnome.tweaks.gschema.xml
SHEBANG_FILES=	gnome-tweak-tool-lid-inhibitor gnome-tweaks \
		meson-postinstall.py
BINARY_ALIAS=	python3=${PYTHON_VERSION}

NO_ARCH=	yes
PORTSCOUT=	limitw:1,even

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
