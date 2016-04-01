# Created by: Murata Shuuichirou <mrt@mickey.ai.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	skkinput
PORTVERSION=	2.06.4
PORTREVISION=	2
CATEGORIES=	japanese x11
MASTER_SITES=	SFJP/skkinput2/6273

MAINTAINER=	koma2@lovepeers.org
COMMENT=	SKK-like Japanese input method for X11

LICENSE=	GPLv2

USES=		imake
USE_XORG=	ice sm x11 xext xt xmu

PLIST_FILES=	bin/skkinput lib/X11/app-defaults/Skkinput \
		man/ja/man1/skkinput.1.gz man/man1/skkinput.1.gz
PORTDOCS=	*.jis ChangeLog skkinputlisp.doc dot.skkinput

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	SKKSERVER
OPTIONS_RADIO_SKKSERVER=DBSKKD RSKKSERV
SKKSERVER_DESC=	Skkserver selection
DBSKKD_DESC=	Use ja-dbskkd-cdb as skkserver
RSKKSERV_DESC=	Use ja-rskkserv as skkserver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBSKKD}
RUN_DEPENDS=	${LOCALBASE}/libexec/dbskkd-cdb:japanese/dbskkd-cdb
.elif ${PORT_OPTIONS:MRSKKSERV}
RUN_DEPENDS=	${LOCALBASE}/libexec/rskkserv:japanese/rskkserv
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:japanese/skkserv
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
# One of the docfiles lives in its own subdirectory; link it relative to
# ${WRKSRC} to simplify installation routine (install all files at once)
	@${LN} ${WRKSRC}/myeval/skkinputlisp.doc ${WRKSRC}/skkinputlisp.doc
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
