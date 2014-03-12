# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kupfer
PORTVERSION=	208
CATEGORIES=	deskutils

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Convenient command and access tool

LICENSE=	GPLv3

BUILD_DEPENDS=	rst2html:${PORTSDIR}/textproc/py-docutils \
		xml2po:${PORTSDIR}/textproc/gnome-doc-utils \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}keyring>=0:${PORTSDIR}/security/py-keyring \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	keybinder>=0:${PORTSDIR}/x11/keybinder \
		${PYTHON_PKGNAMEPREFIX}gdata>=0:${PORTSDIR}/devel/py-gdata

USE_GITHUB=	yes
GH_ACCOUNT=	GNOME
GH_PROJECT=	kupfer
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	0268e36

USES=		desktop-file-utils shared-mime-info
USE_GNOME=	gvfs intltool pygtk2 pygnomedesktop
USE_PYTHON=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.rst

DOCSRCDIR2=	${WRKSRC}/Documentation
DOCSDIR2=	${DOCSDIR}/Documentation
DOC_FILES2=	Contributing.rst GTKTheming.rst PluginAPI.rst VersionHistory.rst

OPTIONS_DEFINE=	DOCS NAUTILUS NLS RHYTHMBOX

OPTIONS_SUB=	yes

NAUTILUS_DESC=	Enable Nautilus support
RHYTHMBOX_DESC=	Enable Rhythmbox plugins support

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NAUTILUS_RUN_DEPENDS=	${LOCALBASE}/lib/nautilus-python/nautilus:${PORTSDIR}/x11-fm/py-nautilus
RHYTHMBOX_RUN_DEPENDS=	rhythmbox:${PORTSDIR}/audio/rhythmbox

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|--quiet||' ${WRKSRC}/bin/kupfer.in
	@${REINPLACE_CMD} -e 's|locale.bindtextdomain|gettext.bindtextdomain|; \
		s|locale.bind_textdomain_codeset|gettext.bind_textdomain_codeset|' \
		${WRKSRC}/kupfer/main.py

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^build_subdirs/s|po||g' ${WRKSRC}/wscript
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf configure \
		--prefix=${STAGEDIR}${PREFIX} --mandir=${STAGEDIR}${PREFIX}/man

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install

post-install:
	${INSTALL_MAN} ${WRKSRC}/build/kupfer.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
