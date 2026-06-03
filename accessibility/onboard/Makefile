PORTNAME=	onboard
DISTVERSION=	1.4.4-1
CATEGORIES=	accessibility

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Simple on-screen keyboard
WWW=	https://github.com/onboard-osk/onboard

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR} \
		evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libcanberra.so:audio/libcanberra \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	iso-codes>0:misc/iso-codes \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycairo>0:graphics/py-pycairo@${PY_FLAVOR}

USES=	gettext-tools gnome pkgconfig python shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-osk
USE_GNOME=	dconf glib20 gtk30 intltool:build pygobject3
GLIB_SCHEMAS=	org.onboard.gschema.xml
USE_PYTHON=	distutils py3kplist
USE_XORG=	x11 xi xkbfile xtst

SHEBANG_FILES=	Onboard/pypredict/tools/checkmodels \
		scripts/toggle-onboard-hoverclick
SHEBANG_GLOB=	*.py

post-patch:
	${REINPLACE_CMD} -i "" -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/Onboard/Config.py \
		${WRKSRC}/Onboard/Indicator.py \
		${WRKSRC}/data/org.onboard.Onboard.service
	${REINPLACE_CMD} -i "" -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/setup.py \
		${WRKSRC}/scripts/sokSettings.py
# Avoid to pollute pkg-plist
	@${FIND} ${WRKSRC} -type f -name '*.orig' -delete

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/org.gnome.shell.extensions.onboard-indicator.gschema.xml
	@${RM} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}/README*

	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Onboard/pypredict/lm${PYTHON_SOABI}.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Onboard/osk${PYTHON_SOABI}.so

.include <bsd.port.mk>
