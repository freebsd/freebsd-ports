# New ports collection makefile for:	skadns
# Date created:		2004-01-01
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skadns
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	dns devel
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Asynchronous DNS client software and library

BUILD_DEPENDS=	${LOCALBASE}/lib/skalibs/libstddjb.a:${PORTSDIR}/devel/skalibs

USE_REINPLACE=	yes

LDFLAGS?=	-s
STRIPFLAGS?=	-x

WRKSRC=		${WRKDIR}/web/${DISTNAME}

DOCS=		package/CHANGES package/README package/THANKS package/TODO \
		doc/*.html

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-compile/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-compile/conf-ld
	${ECHO_CMD} "${STRIP_CMD}"	> ${WRKSRC}/conf-compile/conf-stripbins
	${ECHO_CMD} "${STRIP_CMD} ${STRIPFLAGS}" > ${WRKSRC}/conf-compile/conf-striplibs
	${ECHO_CMD} "FreeBSD"		> ${WRKSRC}/src/sys/systype
	${TOUCH} ${WRKSRC}/src/skadns/socket.lib
	${ECHO_CMD} "${LOCALBASE}/include/skalibs" > ${WRKSRC}/conf-compile/import
	${ECHO_CMD} "${LOCALBASE}/lib/skalibs"    >> ${WRKSRC}/conf-compile/import
	${REINPLACE_CMD} -e 's,/service/skadnsd/.,/var/run/,' \
		-e 's,\$PACKAGE_HOME/skadns/command,${PREFIX}/bin,' \
		${WRKSRC}/src/skadns/skadns.h.stupid

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/library/* ${PREFIX}/lib
	@${MKDIR} ${EXAMPLESDIR}/service/log
	${INSTALL_SCRIPT} ${WRKSRC}/service/skadnsd/run ${EXAMPLESDIR}/service
	${INSTALL_SCRIPT} ${WRKSRC}/service/skadnsd/log/run ${EXAMPLESDIR}/service/log
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
