# New ports collection makefile for:	jasmin
# Date created:			May 26, 2004
# Whom:				Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jasmin
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	java lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	plexus@snafu.de
COMMENT=	Java Assembler Interface

USE_ZIP=	yes
USE_ANT=	yes
ALL_TARGET=	jasmin
USE_JAVA=	1.2+

do-install:
	${INSTALL_DATA} ${WRKSRC}/jasmin.jar ${JAVAJARDIR}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples ; \
	  ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	cd ${WRKSRC}/docs ; \
	  ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

post-install:
	${ENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
