# New ports collection makefile for:	antlr
# Date created:		5 July 2002
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	antlr
PORTVERSION=	2.7.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.ANTLR.org/nirvana/
DISTNAME=	antlr-${PORTVERSION}
DIST_SUBDIR=	antlr
EXTRACT_ONLY=	antlr-${PORTVERSION}.tar.gz

MAINTAINER=	mainland@apeiron.net

BUILD_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

USE_GMAKE=	yes

.if defined(WITH_PARSEVIEW)
DISTFILES+=	ParseView.zip
BUILD_DEPENDS+= ${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

PLIST_SUB+=	PARSEVIEW=""
.else
PLIST_SUB+=	PARSEVIEW="@comment "
.endif

ALL_TARGET=	antlr

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/antlr-${PORTVERSION}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the source distribution (antlr-${PORTVERSION}${EXTRACT_SUFX}) from http://www.jguru.com/jguru/download/view.jsp?EID=201927 (registration required), place it in ${DISTDIR}/${DIST_SUBDIR} and then run make again
.endif

.if defined(WITH_PARSEVIEW)
post-extract:
	(cd ${WRKSRC} && unzip -o ${DISTDIR}/${DIST_SUBDIR}/ParseView.zip)
.endif

post-configure:
	(cd ${WRKSRC}/lib/cpp && ./configure --prefix=${PREFIX})

do-build:
	(cd ${WRKSRC}/lib/cpp && ${GMAKE})

do-install:
	@${SED} "s|%%ANTLR_JAR_PATH%%|${PREFIX}/share/antlr|" ${FILESDIR}/antlr.sh >${WRKDIR}/antlr.sh
	@${MKDIR} ${PREFIX}/share/antlr
	@${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${PREFIX}/bin/antlr
	(cd ${WRKSRC}/lib/cpp && ${GMAKE} install)
	(cd ${WRKSRC} && (${TAR} cf - antlr doc examples/cpp examples/java | ${TAR} xf - -C ${PREFIX}/share/antlr))

.include <bsd.port.post.mk>
