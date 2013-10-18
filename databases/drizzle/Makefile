# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drizzle
PORTVERSION=	2010.05.1561
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/49101349/ \
		LOCAL/glarkin

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A database optimized for Cloud and Net applications

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

USE_GCC=	4.2+
USES=		gmake perl5
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/drizzle

BROKEN=		fails to build

USES=	iconv

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		drizzle
GROUPS=		drizzle

# Replace token in the rc.d script
SUB_LIST+=	USERS=${USERS}

OPTIONS_DEFINE=	DOXYGEN NLS

BUILD_DEPENDS+=	libdrizzle>=0:${PORTSDIR}/databases/libdrizzle \
		e2fsprogs-libuuid>=0:${PORTSDIR}/misc/e2fsprogs-libuuid \
		protobuf>=2.1.0:${PORTSDIR}/devel/protobuf \
		boost-libs>=0:${PORTSDIR}/devel/boost-libs \
		bison>=0:${PORTSDIR}/devel/bison \
		gearmand>=0:${PORTSDIR}/devel/gearmand \
		libmemcached>=0:${PORTSDIR}/databases/libmemcached \
		libevent>=0:${PORTSDIR}/devel/libevent \
		curl>=0:${PORTSDIR}/ftp/curl \
		libgcrypt>=0:${PORTSDIR}/security/libgcrypt \
		pcre>=0:${PORTSDIR}/devel/pcre

MAN1=	drizzle.1 \
	drizzledump.1 \
	drizzleimport.1 \
	drizzleslap.1

MAN8=	drizzled.8

USE_RC_SUBR=	drizzle-server

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--disable-64bit
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen>=0:${PORTSDIR}/devel/doxygen \
		${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
ALL_TARGET=	all doxygen
PLIST_SUB+=	PORTDOCS=""

post-install::
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.include <bsd.port.mk>
