# Created by: rip@pinetec.co.za
# $FreeBSD$

PORTNAME=	cvsmapfs
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.netsw.org/softeng/versioncontrol/repository/cvs/cvsmapfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helps keep track of modes and permissions of files in cvs

EXTRACT_CMD=	${CAT}	# despite .tar.gz suffix, only tarball
EXTRACT_BEFORE_ARGS=
USE_PERL5=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsmapfs ${PREFIX}/bin/cvsmapfs

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
