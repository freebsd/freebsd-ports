# New ports collection makefile for:   ggm
# Date created:        28 May 2008
# Whom:                Sascha Klauder <sklauder@trimind.de>
#
# $FreeBSD$
#

PORTNAME=	gmm
PORTVERSION=	0.9.12
CATEGORIES=	audio
MASTER_SITES=	http://gogglesmm.googlecode.com/files/
DISTNAME=	musicmanager-${PORTVERSION}

MAINTAINER=	sklauder@trimind.de
COMMENT=	Music collection manager and player

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16 \
		xine.1:${PORTSDIR}/multimedia/libxine		\
		tag.6:${PORTSDIR}/audio/taglib			\
		sqlite3.8:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

PORTDOCS=	README AUTHORS
PLIST_FILES=	bin/gmm                         \
		share/pixmaps/gmm.png

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	OPT_CFLAGS=" "

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NEWREMOTE)
CONFIGURE_ARGS+=--without-new-remote
.endif

.if defined(WITH_DBUS)
CONFIGURE_ARGS+=--with-dbus
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
.endif

post-extract:
	${REINPLACE_CMD} -i '' -e "s|/bin/bash|${PREFIX}/bin/bash|" \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/extra/gmm.png ${PREFIX}/share/pixmaps

.include <bsd.port.post.mk>
