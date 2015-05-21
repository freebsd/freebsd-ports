# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kupfer
PORTVERSION=	208
PORTREVISION=	3
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convenient command and access tool

LICENSE=	GPLv3

BROKEN=		Uses unknown GNOME component pygnomedesktop
DEPRECATED=	Broken since update to gnome3
EXPIRATION_DATE=	2015-06-02

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
GH_TAGNAME=	0268e36

USES=		desktop-file-utils python shared-mime-info waf
USE_GNOME=	gvfs intltool pygtk2 pygnomedesktop
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--${PREFIX}/man

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.rst

DOCSRCDIR2=	${WRKSRC}/Documentation
DOCSDIR2=	${DOCSDIR}/Documentation
DOC_FILES2=	Contributing.rst GTKTheming.rst PluginAPI.rst VersionHistory.rst

OPTIONS_DEFINE=	DOCS NLS RHYTHMBOX

OPTIONS_SUB=	yes

RHYTHMBOX_DESC=	Enable Rhythmbox plugins support

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
RHYTHMBOX_RUN_DEPENDS=	rhythmbox:${PORTSDIR}/audio/rhythmbox

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|--quiet||' ${WRKSRC}/bin/${PORTNAME}.in
	@${REINPLACE_CMD} -e 's|locale.bindtextdomain|gettext.bindtextdomain|; \
		s|locale.bind_textdomain_codeset|gettext.bind_textdomain_codeset|' \
		${WRKSRC}/${PORTNAME}/main.py

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^build_subdirs/s|po||g' ${WRKSRC}/wscript
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/build/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
