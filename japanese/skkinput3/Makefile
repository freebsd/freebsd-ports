# Created by: KOMATSU Shinichiro <koma2@jiro.c.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	skkinput3
PORTVERSION=	3.0.6
PORTREVISION=	2
CATEGORIES=	japanese x11
MASTER_SITES=	SFJP/${PORTNAME}/2222
DISTNAME=	skkinput-${PORTVERSION}

MAINTAINER=	koma2@lovepeers.org
COMMENT=	SKK-like Japanese input method for X11

BROKEN_powerpc64=	Does not build

USES=		imake
USE_GCC=	any
USE_CSTD=	gnu89
USE_XORG=	ice sm x11 xext xmu xt
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*.jis dot.skkinput ChangeLog

OPTIONS_DEFINE=	SKK10 DOCS
OPTIONS_RADIO=	SKKSERVER
OPTIONS_RADIO_SKKSERVER=	DBSKKD RSKKSERV

SKKSERVER_DESC=	Skkserver selection
DBSKKD_DESC=	Use ja-dbskkd-cdb as skkserver
RSKKSERV_DESC=	Use ja-rskkserv as skkserver
SKK10_DESC=	Install SKK10 elisp files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSKK10}
PLIST_SUB=	SKK8="@comment " SKK10=""
.else
PLIST_SUB=	SKK8="" SKK10="@comment "
.endif

.if ${PORT_OPTIONS:MDBSKKD}
RUN_DEPENDS=	${LOCALBASE}/libexec/dbskkd-cdb:japanese/dbskkd-cdb
.elif ${PORT_OPTIONS:MRSKKSERV}
RUN_DEPENDS=	${LOCALBASE}/libexec/rskkserv:japanese/rskkserv
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:japanese/skkserv
.endif

post-patch:
.if ${PORT_OPTIONS:MSKK10}
	@${REINPLACE_CMD} -e '/\(#define.*UseSkk8\)/ s/^/XCOMM /' \
		-e '/XCOMM.*#define.*UseSkk10/ s/XCOMM[[:space:]]*//' \
			${WRKSRC}/Skkinput.conf
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
