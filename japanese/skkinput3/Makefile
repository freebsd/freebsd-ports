PORTNAME=	skkinput
PORTVERSION=	3.0.6
PORTREVISION=	11
CATEGORIES=	japanese x11
MASTER_SITES=	OSDN/${PORTNAME}
PKGNAMESUFFIX=	3

MAINTAINER=	koma2@lovepeers.org
COMMENT=	SKK-like Japanese input method for X11
WWW=		https://sourceforge.jp/projects/skkinput3/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

USES=		imake xorg
USE_CSTD=	gnu89
USE_GCC=	yes
USE_XORG=	ice sm x11 xext xmu xt
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*.jis dot.skkinput ChangeLog

OPTIONS_DEFINE=			DOCS SKK10
OPTIONS_DEFAULT=		SKK9
OPTIONS_RADIO=			SKKSERVER
OPTIONS_RADIO_SKKSERVER=	DBSKKD SKK9
OPTIONS_SUB=			yes

DBSKKD_DESC=			Use ja-dbskkd-cdb as skkserver
SKK10_DESC=			Install SKK10 elisp files
SKK9_DESC=			Use ja-skkserv as skkserver
SKKSERVER_DESC=			Skkserver selection

DBSKKD_RUN_DEPENDS=		${LOCALBASE}/libexec/dbskkd-cdb:japanese/dbskkd-cdb
SKK9_RUN_DEPENDS=		${LOCALBASE}/sbin/skkserv:japanese/skkserv

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSKK10}
PLIST_SUB+=	SKK8="@comment "
.else
PLIST_SUB+=	SKK8=""
.endif

post-patch:
.if ${PORT_OPTIONS:MSKK10}
	@${REINPLACE_CMD} -e '/\(#define.*UseSkk8\)/ s/^/XCOMM /' \
		-e '/XCOMM.*#define.*UseSkk10/ s/XCOMM[[:space:]]*//' \
			${WRKSRC}/Skkinput.conf
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
