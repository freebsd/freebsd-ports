# Ports collection makefile for:	Unreal-IRCd
# Date created:				15 April 2004
# Whom:					Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Unreal
PORTVERSION=	3.2.2b
CATEGORIES=	irc
MASTER_SITES=	http://unreal.atlanti-ka.org/ \
		http://unreal.stfu-n00b.net/ \
		http://unrealircd.funny-chat.net/ \
		http://unrealircd.fyrebird.net/ \
		http://unrealircd.chaosteam.hu/ \
		http://64.84.10.70/download/ \
		http://www.gower.net/unrealircd/ \
		http://www.ilmarinen.us/unreal/ \
		http://unrealircd.alert-net.com/ \
		http://www1.dnwt.net/unreal/ \
#		http://www.tiefighter.org/~unreal/downloads/ \  # file missing
#		http://mirror.nimsay-networks.com/unrealircd/ \ # file missing
#		http://unrealircd.za.net/ \                     # file missing
#		ftp://unrealircd.za.net/pub/UnrealIRCd/ \    # connect refused
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tux@pinguru.net
COMMENT=	Unreal - the next generation ircd

WRKSRC=		${WRKDIR}/${PORTNAME}3.2

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-listen=5 \
		--with-dpath=${PREFIX}/Unreal \
		--with-spath=${PREFIX}/Unreal/ircd \
		--with-nick-history=2000 \
		--with-sendq=3000000 \
		--with-bufferpool=18 \
		--with-permissions=0600 \
		--with-fd-setsize=1024 \
		--enable-dynamic-linking

OPTIONS=	HUB "Configure as a hub (otherwise configure as a leaf)" on \
		NOSPOOF "Enable anti-spoof protection" off \
		ZIPLINKS "Enable ziplinks support" off \
		SSL "Support SSL connecions" off \
		IPV6 "Enable ipv6 support" off \
		PREFIXAQ "Enable prefixes for chanadmin and chanowner" off
#		REMOTE "Enable remote includes" off \ this does not work at the moment

SQLMOD=		Unreal/SQLMod.tar.gz

.include <bsd.port.pre.mk>

.if defined(WITH_HUB)
CONFIGURE_ARGS+=	--enable-hub
.endif

.if defined(WITH_NOSPOOF)
CONFIGURE_ARGS+=	--enable-nospoof
.endif

.if defined(WITH_ZIPLINKS)
CONFIGURE_ARGS+=	--enable-ziplinks
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.endif

.if defined(WITH_REMOTE)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-libcurl=${LOCALBASE}
.endif

.if defined(WITH_PREFIXAQ)
CONFIGURE_ARGS+=	--enable-prefixaq
.endif

.if exists(${DISTDIR}/${SQLMOD})
USE_MYSQL=	yes
WITH_SQLMOD=	yes
MAKE_ARGS=	all custommodule MODULEFILE=m_sqlmod
PLIST_FILES+=	Unreal/modules/m_sqlmod.so Unreal/m_sqlmod.conf \
		Unreal/doc/Changes.sqlmod Unreal/doc/README.sqlmod \
		Unreal/doc/LICENSE.sqlmod
.endif

post-extract:
.if defined(WITH_SQLMOD)
	@${TAR} xfz ${DISTDIR}/${SQLMOD} -C ${WRKSRC}
	@${MV} ${WRKSRC}/SQLMod* ${WRKSRC}/SQLMod
	@${CP} -r ${WRKSRC}/SQLMod/m_sqlmod.c ${WRKSRC}/src/modules
.endif

post-patch:
.if defined(WITH_SQLMOD)
	@${PATCH} -d ${WRKSRC} < ${WRKSRC}/SQLMod/patch
.endif

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

post-install:
.if defined(WITH_SQLMOD)
	@${CP} ${WRKSRC}/SQLMod/sample.conf ${PREFIX}/Unreal/m_sqlmod.conf
	@${CP} ${WRKSRC}/SQLMod/Changes ${PREFIX}/Unreal/doc/Changes.sqlmod
	@${CP} ${WRKSRC}/SQLMod/README ${PREFIX}/Unreal/doc/README.sqlmod
	@${CP} ${WRKSRC}/SQLMod/LICENSE ${PREFIX}/Unreal/doc/LICENSE.sqlmod
	@${INSTALL} ${WRKSRC}/src/modules/m_sqlmod.so ${PREFIX}/Unreal/modules/m_sqlmod.so
.endif

.include <bsd.port.post.mk>
