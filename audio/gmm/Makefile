# New ports collection makefile for:   ggm
# Date created:        28 May 2008
# Whom:                Sascha Klauder <sklauder@trimind.de>
#
# $FreeBSD$
#

PORTNAME=	gmm
PORTVERSION=	0.10.22
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://gogglesmm.googlecode.com/files/
DISTNAME=	musicmanager-${PORTVERSION}

MAINTAINER=	sklauder@trimind.de
COMMENT=	Music collection manager and player

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16 		\
		xine.1:${PORTSDIR}/multimedia/libxine		\
		tag.1:${PORTSDIR}/audio/taglib			\
		sqlite3.8:${PORTSDIR}/databases/sqlite3		\
		dbus-1:${PORTSDIR}/devel/dbus			\
		curl.6:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

PORTDOCS=	README AUTHORS

CONFIGURE_ENV=	OPT_CFLAGS=" "

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NEWREMOTE)
CONFIGURE_ARGS+=--without-new-remote
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e "s|/bin/bash|${LOCALBASE}/bin/bash|; \
		s|/usr/local|${LOCALBASE}|" ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -i '' -e 's| -[DT] | |g' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
