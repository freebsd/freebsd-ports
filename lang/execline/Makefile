# New ports collection makefile for:	execline
# Date created:		2003-06-25
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	execline
PORTVERSION=	1.06
CATEGORIES=	lang shells
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Lightweight non-interactive sh(1)-like scripting language

BUILD_DEPENDS=	${LOCALBASE}/lib/skalibs/libstddjb.a:${PORTSDIR}/devel/skalibs

WRKSRC=		${WRKDIR}/admin/${DISTNAME}

DOCS=		package/CHANGES package/README package/THANKS package/TODO \
		doc/*.html

do-configure:
	${ECHO_CMD} "FreeBSD"	> ${WRKSRC}/src/sys/systype
	${ECHO_CMD} "${LOCALBASE}/include/skalibs" \
		> ${WRKSRC}/conf-compile/import
	${ECHO_CMD} "${LOCALBASE}/lib/skalibs" \
		>> ${WRKSRC}/conf-compile/import

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/library/* ${PREFIX}/lib
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
