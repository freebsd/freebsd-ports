# New ports collection makefile for:	netypesv
# Date created:		03 Aug 2001
# Whom:			Takeshi MUTOH <mutoh@info.nara-k.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	netypesv
PORTVERSION=	0.1.0
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.i.his.fukui-u.ac.jp/~funakami/software/netype/src/
DISTNAME=	netypesv-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	mutoh@openedu.org
COMMENT=	Network Type Trainer server program

RUN_DEPENDS=	${JDKDIR}/bin/java:${PORTSDIR}/java/jdk12

SCRIPTS_ENV=	JDKDIR=${JDKDIR} JAVADIR=${JAVADIR} PORTVERSION=${PORTVERSION}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

NO_BUILD=	YES
USE_ZIP=	YES

JAVADIR=	${PREFIX}/share/java
JDKVERSION?=	1.2.2
JDKDIR=		${LOCALBASE}/jdk${JDKVERSION}

NETYPESVDIR=	${JAVADIR}/netypesv-${PORTVERSION}

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/netypesv.in ${WRKSRC}/netypesv

pre-install:
	${MKDIR} ${NETYPESVDIR}/bin ${JAVADIR}/classes
	cd ${WRKDIR}/jp/ac/fukui_u/netypesv; \
	${MV} netypesv.conf netypesv.conf.org; \
	${SED} -e 's#^qfile.*$$#qfile ${NETYPESVDIR}/qlist#g' < netypesv.conf.org > netypesv.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netypesv ${NETYPESVDIR}/bin
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVADIR}/classes
	cd ${WRKDIR}/jp/ac/fukui_u/netypesv; \
	${INSTALL_DATA} qlist ${NETYPESVDIR}; \
	${INSTALL_DATA} netypesv.conf ${NETYPESVDIR}
	${LN} -sf ${NETYPESVDIR}/bin/netypesv ${PREFIX}/bin/netypesv

.include <bsd.port.mk>
