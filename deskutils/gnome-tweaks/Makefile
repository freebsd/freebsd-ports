PORTNAME=	gnome-tweaks
PORTVERSION=	46.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GNOME
WWW=		https://gitlab.gnome.org/GNOME/gnome-tweaks

LICENSE=	CC0-1.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev
RUN_DEPENDS=	gnome-shell>=47.0:x11/gnome-shell \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext gnome localbase meson pkgconfig \
		python shebangfix tar:xz
USE_GNOME=	glib20 gnomedesktop4 gtk40 introspection libadwaita pygobject3
GLIB_SCHEMAS=	org.gnome.tweaks.gschema.xml
SHEBANG_FILES=	gnome-tweaks meson-postinstall.py
BINARY_ALIAS=	python3=${PYTHON_VERSION}

NO_ARCH=	yes

post-patch:
# Downgrade devel/libgudev
	${REINPLACE_CMD} -e 's|238|237|' \
		${WRKSRC}/meson.build

	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/gnome-tweaks
	${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' \
		${WRKSRC}/gtweak/gsettings.py \
		${WRKSRC}/gtweak/gshellwrapper.py

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
