# New ports collection makefile for:	rbldnsd
# Date created:				Fri Jun 13 05:30:12 EDT 2003
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	rbldnsd
PORTVERSION=	0.996b
CATEGORIES=	dns
MASTER_SITES=	http://www.corpit.ru/mjt/rbldnsd/:0 \
		http://www.it.ca/~paul/src/:0
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}:0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast DNS daemon especially for DNSBL zones

.if !defined(NOPORTDOCS)
EXTRACT_ONLY+=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}
MASTER_SITES+=	http://www.corpit.ru/mjt/:1 \
		http://www.it.ca/~paul/src/:1
DISTFILES+=	rbldnsd.html:1
IGNOREFILES+=	rbldnsd.html
.endif

RBLDNSUSER=	rbldns
RBLDNSGROUP=	${RBLDNSUSER}
ROOTDIR=	${PREFIX}/etc/rbldnsd/

MAN8=		rbldnsd.8

HAS_CONFIGURE=	yes
USE_RC_SUBR=	rbldnsd
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

pre-install:
		@${ECHO} "==>  Creating custom user to run rbldnsd..."
		@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
		@if [ ! -d ${ROOTDIR} ]; then \
			${MKDIR} ${ROOTDIR}; \
			${CHMOD} 710 ${ROOTDIR}; \
			${CHGRP} ${RBLDNSGROUP} ${ROOTDIR}; \
		fi
		@${INSTALL_DATA} -g ${RBLDNSUSER} -m 640 ${FILESDIR}/example ${PREFIX}/etc/rbldnsd/
		@${INSTALL_PROGRAM} ${WRKSRC}/rbldnsd ${PREFIX}/sbin/
		@${INSTALL_MAN} ${WRKSRC}/rbldnsd.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/CHANGES-0.81 ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/debian/copyright ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/debian/rbldnsd.default ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/debian/rbldnsd.init ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/rbldnsd.spec ${DOCSDIR}
		@${INSTALL_DATA} ${DISTDIR}/rbldnsd.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
