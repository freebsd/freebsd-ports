# Created by: gahr
# $FreeBSD$

PORTNAME=	codelite
DISTVERSION=	5.0.${SVN_REVISION}
CATEGORIES=	editors devel
MASTER_SITES=	SF/${PORTNAME}/Releases/${PORTNAME}-${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-gtk.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An Open Source IDE for C/C++

LICENSE=	GPLv2

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

OPTIONS_DEFINE=	CSCOPE CLANG MYSQL PGSQL

CSCOPE_DESC=	CScope integration
CLANG_DESC=	Clang code-completion

USE_WX=		2.9
WX_UNICODE=	yes
USE_DOS2UNIX=	*.cpp
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CPPFLAGS+=	-g -O0
CONFIGURE_ARGS+=--enable-debug \
		--prefix=${PREFIX}
CONFIGURE_ENV+=	WXCONFIG=${WX_CONFIG}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SVN_REVISION=	6213

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCSCOPE}
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
.endif

.if ${PORT_OPTIONS:MCLANG}
.if ${OSVERSION} < 1000026
BUILD_DEPENDS+=	${LOCALBASE}/lib/libclang.so:${PORTSDIR}/lang/clang
RUN_DEPENDS+=	${LOCALBASE}/lib/libclang.so:${PORTSDIR}/lang/clang
.endif
PLIST_SUB+=	CLANG=""
.else
CONFIGURE_ARGS+=--without-clang
ENABLE_CLANG=	\#
PLIST_SUB+=	CLANG="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=--enable-mysql
USE_MYSQL=	client
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=--enable-postgres
USE_PGSQL=	yes
PLIST_SUB+=	POSTGRES=""
.else
PLIST_SUB+=	POSTGRES="@comment "
.endif

post-patch:
#	Use the correct wx-config
	${REINPLACE_CMD} -e 's|%%ENABLE_CLANG%%|${ENABLE_CLANG}|g; \
	   s|%%LOCALBASE%%|${LOCALBASE}|g; s|666|644|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$${cur_rev}|${SVN_REVISION}|' \
	    ${WRKSRC}/le_makerevision.sh
# 	CTags already installed
.if exists(${LOCALBASE}/include/readtags.h)
	${RM} ${WRKSRC}/CodeLite/readtags.h
.endif

.include <bsd.port.mk>
