# New ports collection makefile for:	cvsweb
# Version required:	1.0
# Date created:		27 Jun 1999
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	cvsweb-1.0
CATEGORIES=	devel www
MASTER_SITES=	http://www.freebsd.org/~fenner/cvsweb/

MAINTAINER=	sada@FreeBSD.org

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
.if !defined(PACKAGE_BUILDING)
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL
.endif
	@${MKDIR} ${PREFIX}/share/apache/cgi-bin
	@${INSTALL_SCRIPT} ${WRKDIR}/cvsweb ${PREFIX}/share/apache/cgi-bin/

.include <bsd.port.mk>
