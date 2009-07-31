# New ports collection makefile for:   ggm
# Date created:        28 May 2008
# Whom:                Sascha Klauder <sklauder@trimind.de>
#
# $FreeBSD$
#

PORTNAME=	gmm
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://gogglesmm.googlecode.com/files/
DISTNAME=	musicmanager-${PORTVERSION}

MAINTAINER=	sklauder@trimind.de
COMMENT=	Music collection manager and player

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16 		\
		xine.1:${PORTSDIR}/multimedia/libxine		\
		tag.6:${PORTSDIR}/audio/taglib			\
		sqlite3.8:${PORTSDIR}/databases/sqlite3		\
		dbus-1:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
WANT_GNOME=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

PORTDOCS=	README AUTHORS
PLIST_DIRS=	share/applications
PLIST_FILES=	bin/gmm						\
		share/applications/gmm.desktop			\
		share/icons/hicolor/48x48/apps/gmm.png		\
		share/locale/de/LC_MESSAGES/gogglesmm.mo

CONFIGURE_ENV=	OPT_CFLAGS=" "

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NEWREMOTE)
CONFIGURE_ARGS+=--without-new-remote
.endif

post-extract:
	${REINPLACE_CMD} -i '' -e "s|/bin/bash|${PREFIX}/bin/bash|" \
		${WRKSRC}/configure

post-configure:
	${REINPLACE_CMD} -i '' -e 's| -D | |' \
		${WRKSRC}/Makefile

	${REINPLACE_CMD} -i '' -e 's| -T | |' \
		${WRKSRC}/Makefile

pre-install:
	[ -d ${PREFIX}/share/applications ] ||	\
	    ${MKDIR} ${PREFIX}/share/applications

	[ -d ${PREFIX}/share/locale/de/LC_MESSAGES ] ||
	    ${MKDIR} ${PREFIX}/share/locale/de/LC_MESSAGES

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
