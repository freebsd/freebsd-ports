# New ports collection makefile for:	skkinput
# Date created:		28 Jan 1998
# Whom:			Murata Shuuichirou <mrt@mickey.ai.kyutech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skkinput
PORTVERSION=	2.06.4
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	skkinput2/6273

MAINTAINER=	koma2@ms.u-tokyo.ac.jp
COMMENT=	An SKK-like Japanese input method for X11

USE_IMAKE=	yes

OPTIONS=	DBSKKD "Use ja-dbskkd-cdb as skkserver" off \
		RSKKSERV "Use ja-rskkserv as skkserver" off

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

MANLANG=	"" ja
MAN1=		skkinput.1
MANCOMPRESSED=	yes

DOCS=		*.jis ChangeLog \
		myeval/skkinputlisp.doc dot.skkinput

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@( cd ${WRKSRC} ; ${INSTALL_DATA} ${DOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
