# Ports collection makefile for:	Unreal-IRCd
# Date created:				15 April 2004
# Whom:					Gerrit Beine (<tux@pinguru.net>)
# ToDo:	Make the configuration more flexible using -DOPTION for the
#	configuration values, especially support for IPv6.
#
# $FreeBSD$
#

PORTNAME=	Unreal
PORTVERSION=	3.2.1
CATEGORIES=	irc
MASTER_SITES=	http://mirror.nimsay-networks.com/unrealircd/ \
		http://unrealircd.za.net/ \
		ftp://unrealircd.za.net/pub/UnrealIRCd/
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tux@pinguru.net
COMMENT=	Unreal - the next generation ircd

SQLMOD=		Unreal/SQLMod.tar.gz

WRKSRC=		${WRKDIR}/${PORTNAME}3.2

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-nospoof \
		--enable-hub \
		--enable-ziplinks \
		--with-listen=5 \
		--with-dpath=${PREFIX}/Unreal \
		--with-spath=${PREFIX}/Unreal/ircd \
		--with-nick-history=2000 \
		--with-sendq=3000000 \
		--with-bufferpool=18 \
		--with-permissions=0600 \
		--with-fd-setsize=1024 \
		--enable-dynamic-linking

.include <bsd.port.pre.mk>

.if exists(${DISTDIR}/${SQLMOD})
USE_MYSQL=	yes
WITH_SQLMOD=	yes
MAKE_ARGS=	all custommodule MODULEFILE=m_sqlmod
PLIST_FILES+=	Unreal/modules/m_sqlmod.so Unreal/m_sqlmod.conf \
		Unreal/doc/Changes.sqlmod Unreal/doc/README.sqlmod \
		Unreal/doc/LICENSE.sqlmod
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
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

post-install:
.if defined(WITH_SQLMOD)
	@${CP} ${WRKSRC}/SQLMod/sample.conf ${PREFIX}/Unreal/m_sqlmod.conf
	@${CP} ${WRKSRC}/SQLMod/Changes ${PREFIX}/Unreal/doc/Changes.sqlmod
	@${CP} ${WRKSRC}/SQLMod/README ${PREFIX}/Unreal/doc/README.sqlmod
	@${CP} ${WRKSRC}/SQLMod/LICENSE ${PREFIX}/Unreal/doc/LICENSE.sqlmod
	@${INSTALL} ${WRKSRC}/src/modules/m_sqlmod.so ${PREFIX}/Unreal/modules/m_sqlmod.so
.endif

.include <bsd.port.post.mk>
