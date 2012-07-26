# New ports collection makefile for:   ggm
# Date created:        28 May 2008
# Whom:                Sascha Klauder <sklauder@trimind.de>
#
# $FreeBSD$
#

PORTNAME=	gogglesmm
PORTVERSION=	0.12.6
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Music collection manager and player

LICENSE=	GPLv3

LIB_DEPENDS=	xine.2:${PORTSDIR}/multimedia/libxine \
		tag.1:${PORTSDIR}/audio/taglib	\
		sqlite3.8:${PORTSDIR}/databases/sqlite3

OPTIONS_DEFINE=	DBUS CURL NLS NEWREMOTE GCRYPT DOCS
OPTIONS_SINGLE=	FOX
OPTIONS_SINGLE_FOX=	FOX16 FOX17
OPTIONS_DEFAULT=	DBUS CURL NEWREMOTE FOX16

FOX16_DESC=	Use stable branch of FOX
FOX17_DESC=	Use development branch of FOX
NEWREMOTE_DESC=	Use new remote player
GCRYPT_DESC=	Use libgcrypt for md5 calculation

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man --prefix=${PREFIX}
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	yes
USE_XZ=		yes
INSTALLS_ICONS=	yes
MAN1=		gogglesmm.1

PORTDOCS=	README AUTHORS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFOX16}
LIB_DEPENDS+=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16
.endif

.if ${PORT_OPTIONS:MFOX17}
LIB_DEPENDS+=	FOX-1.7:${PORTSDIR}/x11-toolkits/fox17
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt.18:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--with-md5=gcrypt
.else
CONFIGURE_ARGS+=	--with-md5=internal
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB=	NLS=""
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.if empty(PORT_OPTIONS:MNEWREMOTE)
CONFIGURE_ARGS+=--without-new-remote
.endif

post-patch:
	@${ECHO_CMD} ${SUBPORT}

pre-install:
	@${MKDIR} ${PREFIX}/share/applications

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
