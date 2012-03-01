# New ports collection makefile for: 	codelite
# Date created:				7 May 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	codelite
DISTVERSION=	3.5.${SVN_REVISION}
CATEGORIES=	editors devel
MASTER_SITES=	SF/${PORTNAME}/Releases/${PORTNAME}-${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-gtk.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An Open Source IDE for C/C++

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

OPTIONS=	CSCOPE	"Enable CScope integration" OFF \
		CLANG "Enable clang code-completion" OFF \
		MYSQL "Enable MySQL in DB Explorer plugin" OFF \
		POSTGRES "Enable PostgreSQL in DB Explorer plugin" OFF

USE_WX=		2.8
WX_UNICODE=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-debug

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

SVN_REVISION=	5375

.if defined(WITH_CSCOPE)
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
.endif

.if defined(WITH_CLANG)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libclang.so:${PORTSDIR}/lang/clang
RUN_DEPENDS+=	${LOCALBASE}/lib/libclang.so:${PORTSDIR}/lang/clang
PLIST_SUB+=	CLANG=""
.else
ENABLE_CLANG=	\#
PLIST_SUB+=	CLANG="@comment "
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=--enable-mysql
USE_MYSQL=	client
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_POSTGRES)
CONFIGURE_ARGS+=--enable-postgres
USE_PGSQL=	yes
PLIST_SUB+=	POSTGRES=""
.else
PLIST_SUB+=	POSTGRES="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g; s|%%ENABLE_CLANG%%|${ENABLE_CLANG}|g; \
	   s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure
#	Configure script does not respect --prefix
	${REINPLACE_CMD} -e '/^prefix/s|/usr|${PREFIX}|; \
	    /^plugins_dir/s|/usr/lib/codelite|${DATADIR}/plugins|' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$${cur_rev}|${SVN_REVISION}|' \
	    ${WRKSRC}/le_makerevision.sh
# 	CTags already installed
.if exists(${LOCALBASE}/include/readtags.h)
	${RM} ${WRKSRC}/CodeLite/readtags.h
.endif

.include <bsd.port.post.mk>
