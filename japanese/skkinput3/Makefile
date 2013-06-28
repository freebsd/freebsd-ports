# Created by: KOMATSU Shinichiro <koma2@jiro.c.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	skkinput3
PORTVERSION=	3.0.6
PORTREVISION=	2
CATEGORIES=	japanese x11
MASTER_SITES=	http://downloads.sourceforge.jp/skkinput3/2222/
DISTNAME=	skkinput-${PORTVERSION}

MAINTAINER=	koma2@lovepeers.org
COMMENT=	SKK-like Japanese input method for X11

USES=		imake
USE_GCC=	any
USE_XORG=	ice sm x11 xext xmu xt

OPTIONS_DEFINE=	SKK10
OPTIONS_RADIO=	RG1
OPTIONS_RADIO_RG1=	DBSKKD RSKKSERV
RG1_DESC=	Skkserver Selection
DBSKKD_DESC=	Use ja-dbskkd-cdb as skkserver
RSKKSERV_DESC=	Use ja-rskkserv as skkserver
SKK10_DESC=	Use SKK10 elisps
USE_CSTD=	gnu89

NO_INSTALL_MANPAGES=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSKK10}
PLIST_SUB=		SKK8="@comment " SKK10=""
.else
PLIST_SUB=		SKK8="" SKK10="@comment "
.endif

.if ${PORT_OPTIONS:MDBSKKD}
RUN_DEPENDS=	${LOCALBASE}/libexec/dbskkd-cdb:${PORTSDIR}/japanese/dbskkd-cdb
.elif ${PORT_OPTIONS:MRSKKSERV}
RUN_DEPENDS=	${LOCALBASE}/libexec/rskkserv:${PORTSDIR}/japanese/rskkserv
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skkserv
.endif

DOCS=		*.jis dot.skkinput ChangeLog

.if ${PORT_OPTIONS:MSKK10}
post-patch:
	${REINPLACE_CMD} -e '/\(#define.*UseSkk8\)/ s/^/XCOMM /' \
	                 -e '/XCOMM.*#define.*UseSkk10/ s/XCOMM[[:space:]]*//' \
			 ${WRKSRC}/Skkinput.conf
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
