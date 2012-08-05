# New ports collection makefile for:	drizzle
# Date created:		2010-04-22
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drizzle
PORTVERSION=	2010.05.1561
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/49101349/ \
		LOCAL/glarkin

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A database optimized for Cloud and Net applications

USE_GCC=	4.2+
USE_PERL5=	5.6.0+
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/drizzle

USE_ICONV=	yes

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		drizzle
GROUPS=		drizzle

# Replace token in the rc.d script
SUB_LIST+=	USERS=${USERS}

OPTIONS=	DOCS "Build documentation with doxygen (very slow)" Off

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--disable-64bit
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if !defined(NOPORTDOCS)
.if defined(WITH_DOCS)
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
.endif

.include <bsd.port.post.mk>
