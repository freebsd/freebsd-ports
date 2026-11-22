PORTNAME=	skkinput
PORTVERSION=	2.06.4
PORTREVISION=	5
CATEGORIES=	japanese x11
MASTER_SITES=	https://ftp.iij.ad.jp/pub/sourceforge.jp/skkinput2/6273/

MAINTAINER=	mce@FreeBSD.org
COMMENT=	SKK-like Japanese input method for X11

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

USES=		imake xorg
USE_XORG=	ice sm x11 xext xt xmu

PLIST_FILES=	bin/skkinput lib/X11/app-defaults/Skkinput \
		share/man/ja/man1/skkinput.1.gz share/man/man1/skkinput.1.gz
PORTDOCS=	*.jis ChangeLog skkinputlisp.doc dot.skkinput

OPTIONS_DEFINE=			DOCS
OPTIONS_DEFAULT=		SKK9
OPTIONS_RADIO=			SKKSERVER
OPTIONS_RADIO_SKKSERVER=	DBSKKD MULTISKKSERV SKK9
DBSKKD_DESC=			Use ja-dbskkd-cdb as skkserver
MULTISKKSERV_DESC=		Use ja-multiskkserv as skkserver
SKK9_DESC=			Use ja-skkserv as skkserver
SKKSERVER_DESC=			Skkserver selection

DBSKKD_RUN_DEPENDS=		${LOCALBASE}/libexec/dbskkd-cdb:japanese/dbskkd-cdb
MULTISKKSERV_RUN_DEPENDS=	${LOCALBASE}/sbin/multiskkserv:japanese/multiskkserv
SKK9_RUN_DEPENDS=		${LOCALBASE}/sbin/skkserv:japanese/skkserv

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
# One of the docfiles lives in its own subdirectory; link it relative to
# ${WRKSRC} to simplify installation routine (install all files at once)
	@${LN} ${WRKSRC}/myeval/skkinputlisp.doc ${WRKSRC}/skkinputlisp.doc
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
