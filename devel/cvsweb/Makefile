# New ports collection makefile for:	cvsweb
# Version required:	1.0
# Date created:		27 Jun 1999
# Whom:			SADA Kenji <sada@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1999/06/28 17:26:34 sada Exp $
#

DISTNAME=	cvsweb-1.0
CATEGORIES=	net www
MASTER_SITES=	http://www.freebsd.org/~fenner/cvsweb/

MAINTAINER=	sada@FreeBSD.ORG

NO_BUILD=	yes

# could be overridden.
CVSROOT?=	'/home/ncvs'
CVSWEB_CVSROOT?= ${CVSROOT}
CVSWEB_TITLE?=	'My CVS Tree'
.if defined(PACKAGE_BUILDING)
CVSWEB_CVSROOT=	/home/ncvs
.endif

do-configure:
	@${SED} -e "s;@@CVSROOT@@;${CVSWEB_CVSROOT};g" \
		-e "s;@@TITLE@@;${CVSWEB_TITLE};g" \
		${WRKSRC}/cvsweb > ${WRKDIR}/cvsweb

do-install:
	@if PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL; then \
		${MKDIR} ${PREFIX}/www/cgi-bin; \
		${INSTALL_SCRIPT} ${WRKDIR}/cvsweb ${PREFIX}/www/cgi-bin/; \
	else \
		exit 1; \
	fi

.include <bsd.port.mk>
