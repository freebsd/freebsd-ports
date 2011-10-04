# New ports collection makefile for:   ggm
# Date created:        28 May 2008
# Whom:                Sascha Klauder <sklauder@trimind.de>
#
# $FreeBSD$
#

PORTNAME=	gogglesmm
PORTVERSION=	0.12.3
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Music collection manager and player

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine \
		tag.1:${PORTSDIR}/audio/taglib	\
		sqlite3.8:${PORTSDIR}/databases/sqlite3

OPTIONS=	DBUS "Add DBUS support" on \
		CURL "Add Curl support" on \
		NLS "Add support for nls" on \
		NEWREMOTE "Use new remote player" on \
		FOX16 "Use stable branch of  FOX" on \
		FOX17 "Use development branch of FOX" off \
		GCRYPT "Use libgcrypt for md5 calculation" off

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man --prefix=${PREFIX}
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_XZ=		yes
INSTALLS_ICONS=	yes
MAN1=		gogglesmm.1

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	README AUTHORS

.include <bsd.port.options.mk>
.if (defined(WITHOUT_FOX16) && defined(WITHOUT_FOX17)) || (defined(WITH_FOX16) && defined(WITH_FOX17))
IGNORE=	you should choose between FOX16 and FOX17
.endif

.if defined(WITH_FOX16)
LIB_DEPENDS+=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16
.endif

.if defined(WITH_FOX17)
LIB_DEPENDS+=	FOX-1.7:${PORTSDIR}/x11-toolkits/fox17
.endif

.if defined(WITH_GCRYPT)
LIB_DEPENDS+=	gcrypt.18:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--with-md5=gcrypt
.else
CONFIGURE_ARGS+=	--with-md5=internal
.endif

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

pre-install:
	@${MKDIR} ${PREFIX}/share/applications

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
