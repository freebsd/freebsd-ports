# New ports collection makefile for:	skkinput
# Date created:		28 Jan 1998
# Whom:			Murata Shuuichirou <mrt@mickey.ai.kyutech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skkinput
PORTVERSION=	2.06.3
CATEGORIES=	japanese x11
MASTER_SITES=	http://downloads.sourceforge.jp/skkinput2/1815/

MAINTAINER=	koma2@jiro.c.u-tokyo.ac.jp

USE_IMAKE=	yes

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
