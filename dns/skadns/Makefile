# New ports collection makefile for:	skadns
# Date created:		2004-01-01
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skadns
PORTVERSION=	0.23
CATEGORIES=	dns devel
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Asynchronous DNS client software and library

BUILD_DEPENDS=	${LOCALBASE}/lib/skalibs/libstddjb.a:${PORTSDIR}/devel/skalibs

USE_REINPLACE=	yes

LDFLAGS?=	-s

WRKSRC=		${WRKDIR}/web/${DISTNAME}

DOCS=		package/CHANGES package/README package/THANKS package/TODO \
		doc/*.html

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/src/sys/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/src/sys/conf-ld
	${ECHO_CMD} "FreeBSD"		> ${WRKSRC}/src/sys/systype
	${ECHO_CMD} "${LOCALBASE}/include/skalibs" > ${WRKSRC}/package/import
	${ECHO_CMD} "${LOCALBASE}/lib/skalibs"    >> ${WRKSRC}/package/import
	${REINPLACE_CMD} -e 's,/service/skadnsd/.,/var/run/,' \
		-e 's,/package/web/skadns/command,${PREFIX}/bin,' \
		${WRKSRC}/src/skadns/skadns.h

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/library/* ${PREFIX}/lib
	@${MKDIR} ${EXAMPLESDIR}/service
	cd ${WRKSRC}/service/skadnsd && ${TAR} cf - * | \
		(cd ${EXAMPLESDIR}/service && ${TAR} xf -)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
