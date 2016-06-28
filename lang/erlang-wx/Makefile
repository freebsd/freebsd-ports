# $FreeBSD$

PORTNAME=	erlang
PORTVERSION=	18.3.4.1
CATEGORIES=	lang parallel
MASTER_SITES=	http://www.erlang.org/download/:erlangorg		\
		http://erlang.stacken.kth.se/download/:erlangorg	\
		http://www.csd.uu.se/ftp/mirror/erlang/download/:erlangorg
PKGNAMESUFFIX=	-wx
DISTNAME=	otp_src_${ERL_RELEASE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:erlangorg
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://olgeni.olgeni.com/~olgeni/distfiles/ \
		LOCAL/olgeni
PATCHFILES=	patch-otp-18.3.1 patch-otp-18.3.2 patch-otp-18.3.3 \
		patch-otp-18.3.4 patch-otp-18.3.4.1

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang bindings for wxWindows

LICENSE=	APACHE20

RUN_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang

WRKSRC=		${WRKDIR}/otp_src_${ERL_RELEASE}

PLIST_SUB=	APP_VERSION=${APP_VERSION} \
		CONFIGURE_TARGET=${CONFIGURE_TARGET}

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

ERL_RELEASE=	18.3

USES=		gmake
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

APP_VERSION=	1.6.1
APP_DIR=	${PREFIX}/lib/erlang/lib/wx-${APP_VERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${ERLANG_DOCS}:erlangorg
.endif

CONFIGURE_ARGS+=--enable-threads --without-odbc --without-javac --with-wx-config=${WX_CONFIG}

USE_WX=		2.8+
WX_COMPS=	wx contrib

ERLANG_DOCS=	otp_doc_html_${ERL_RELEASE}.tar.gz

.if ${ARCH} == i386
MAKE_ARGS+=	ARCH=x86
.endif

do-build:
	cd ${WRKSRC}/lib/wx && ${GMAKE} ERL_TOP=${WRKSRC} TARGET=${CONFIGURE_TARGET}
	${STRIP_CMD} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/erl_gl.so
	${STRIP_CMD} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/wxe_driver.so

do-install:
	@${MKDIR} ${STAGEDIR}${APP_DIR}
	cd ${WRKSRC}/lib/wx && ${COPYTREE_SHARE} ebin ${STAGEDIR}${APP_DIR}
	cd ${WRKSRC}/lib/wx && ${COPYTREE_SHARE} include ${STAGEDIR}${APP_DIR}
	cd ${WRKSRC}/lib/wx && ${COPYTREE_SHARE} priv ${STAGEDIR}${APP_DIR}
	cd ${WRKSRC}/lib/wx && ${COPYTREE_SHARE} src ${STAGEDIR}${APP_DIR}
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/lib/wx && ${COPYTREE_SHARE} doc ${STAGEDIR}${APP_DIR}
	${RMDIR} ${STAGEDIR}${APP_DIR}/doc/man3
	${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_DOCS} \
		-C ${STAGEDIR}${PREFIX}/lib/erlang lib/wx-${APP_VERSION}
.endif

.include <bsd.port.mk>
