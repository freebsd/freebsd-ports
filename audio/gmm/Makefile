# New ports collection makefile for:   ggm
# Date created:        28 May 2008
# Whom:                Sascha Klauder <sklauder@trimind.de>
#
# $FreeBSD$
#

PORTNAME=	gmm
PORTVERSION=	0.10.26
CATEGORIES=	audio
MASTER_SITES=	http://gogglesmm.googlecode.com/files/
DISTNAME=	gogglesmm-${PORTVERSION}

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Music collection manager and player

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16 		\
		xine.1:${PORTSDIR}/multimedia/libxine		\
		tag.1:${PORTSDIR}/audio/taglib			\
		sqlite3.8:${PORTSDIR}/databases/sqlite3

OPTIONS=	DBUS "Add DBUS support" on \
		CURL "Add Curl support" on \
		NLS "Add support for nls" on \
		NEWREMOTE "Use new remote player" on

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_XZ=		yes
INSTALLS_ICONS=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	README AUTHORS

CONFIGURE_ENV=	OPT_CFLAGS=" "

.include <bsd.port.options.mk>
.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--without-dbus
.else
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
.endif

.if defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--without-curl
.else
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.else
PLIST_SUB=	NLS=""
USE_GETTEXT=	yes
.endif

.if defined(WITHOUT_NEWREMOTE)
CONFIGURE_ARGS+=--without-new-remote
.endif

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

.include <bsd.port.mk>
