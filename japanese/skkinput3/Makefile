# New ports collection makefile for:	skkinput3
# Date created:		Aug 14 2002
# Whom:			KOMATSU Shinichiro <koma2@jiro.c.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skkinput3
PORTVERSION=	3.0.6
CATEGORIES=	japanese x11
MASTER_SITES=	http://downloads.sourceforge.jp/skkinput3/2222/
DISTNAME=	skkinput-${PORTVERSION}

MAINTAINER=	koma2@lovepeers.org
COMMENT=	An SKK-like Japanese input method for X11

USE_IMAKE=		yes

NO_INSTALL_MANPAGES=	yes

.if defined(USE_SKK10)
USE_REINPLACE=		yes
PLIST_SUB=		SKK8="@comment " SKK10=""
.else
PLIST_SUB=		SKK8="" SKK10="@comment "
.endif

.include <bsd.port.pre.mk>

# sanity check
.if defined(WITH_DBSKKD) && defined(WITH_RSKKSERV)
.error Cannot define both WITH_DBSKKD and WITH_RSKKSERV simultaneously.
.endif

.if defined(WITH_DBSKKD) || exists(${LOCALBASE}/libexec/dbskkd-cdb) && !defined(WITH_RSKKSERV)
RUN_DEPENDS=	${LOCALBASE}/libexec/dbskkd-cdb:${PORTSDIR}/japanese/dbskkd-cdb
.elif defined(WITH_RSKKSERV) || exists(${LOCALBASE}/libexec/rskkserv) && !defined(WITH_DBSKKD)
RUN_DEPENDS=	${LOCALBASE}/libexec/rskkserv:${PORTSDIR}/japanese/rskkserv
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skkserv
.endif

DOCS=		*.jis dot.skkinput ChangeLog

.if defined(USE_SKK10)
post-patch:
	${REINPLACE_CMD} -e '/\(#define.*UseSkk8\)/ s/^/XCOMM /' \
	                 -e '/XCOMM.*#define.*UseSkk10/ s/XCOMM[[:space:]]*//' \
			 ${WRKSRC}/Skkinput.conf
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
