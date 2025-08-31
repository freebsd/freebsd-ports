PORTNAME=	gnome-shell-extension-coverflow
PORTVERSION=	0.0.0.20180110
PORTREVISION=	3
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lets you Alt-Tab windows in a cover-flow manner
WWW=		https://github.com/dmo60/CoverflowAltTab

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Does not support recent gnome-shell

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome localbase pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes

GLIB_SCHEMAS=	org.gnome.shell.extensions.coverflowalttab.gschema.xml

GH_ACCOUNT=	dmo60
GH_TAGNAME=	991e743
GH_PROJECT=	CoverflowAltTab

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"3.26"|"3.26","3.28"|g' \
		${WRKSRC}/CoverflowAltTab@dmo60.de/metadata.json

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/
		@(cd ${WRKSRC} && ${CP} CoverflowAltTab\@dmo60.de/schemas/org.gnome.shell.extensions.coverflowalttab.gschema.xml \
			${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/)
		@${RM} -r ${WRKSRC}/CoverflowAltTab\@dmo60.de/schemas
		@(cd ${WRKSRC} && ${CP} -pPR CoverflowAltTab\@dmo60.de ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/)

.include <bsd.port.mk>
