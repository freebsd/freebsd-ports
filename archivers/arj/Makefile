# New ports collection makefile for:	ARJ archiver
# Date created:			9 April 2002
# Whom:				Konstantin Reznichenko <kot@premierbank.dp.ua>
#
# $FreeBSD$
#

PORTNAME=	arj
PORTVERSION=	3.10b
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://testcase.newmail.ru/files/
MASTER_SITE_SUBDIR=	keramida

MAINTAINER=	kot@premierbank.dp.ua

USE_AUTOCONF=	yes
USE_GMAKE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/gnu
MAKEFILE=	makefile.gnu

pre-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} prepare)

do-install:
.for f in arj rearj arjdisp register
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${OSREL}/en/rs/$f/$f ${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${OSREL}/en/rs/arjcrypt/arjcrypt.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} COPYING debug.txt ${DOCSDIR}
	cd ${WRKSRC}/resource/en && \
		${INSTALL_DATA} arjl.txt arjs.txt history.txt readme.txt unix.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
