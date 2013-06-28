# Created by: Murata Shuuichirou <mrt@mickey.ai.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	skkinput
PORTVERSION=	2.06.4
PORTREVISION=	2
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	skkinput2/6273

MAINTAINER=	koma2@lovepeers.org
COMMENT=	SKK-like Japanese input method for X11

USES=		imake
USE_XORG=	ice sm x11 xext xt xmu

OPTIONS_RADIO=	RG1
OPTIONS_RADIO_RG1=	DBSKKD RSKKSERV
RG1_DESC=	Skkserver Selection
DBSKKD_DESC=	Use ja-dbskkd-cdb as skkserver
RSKKSERV_DESC=	Use ja-rskkserv as skkserver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBSKKD}
RUN_DEPENDS=	${LOCALBASE}/libexec/dbskkd-cdb:${PORTSDIR}/japanese/dbskkd-cdb
.elif ${PORT_OPTIONS:MRSKKSERV}
RUN_DEPENDS=	${LOCALBASE}/libexec/rskkserv:${PORTSDIR}/japanese/rskkserv
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skkserv
.endif

MANLANG=	"" ja
MAN1=		skkinput.1
MANCOMPRESSED=	yes

DOCS=		*.jis ChangeLog \
		myeval/skkinputlisp.doc dot.skkinput

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	@( cd ${WRKSRC} ; ${INSTALL_DATA} ${DOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
