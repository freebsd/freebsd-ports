# New ports collection makefile for:	cvsmapfs
# Date created:		17 January 2000
# Whom:			rip@pinetec.co.za
#
# $FreeBSD$
#

PORTNAME=	cvsmapfs
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.netsw.org/softeng/versioncontrol/repository/cvs/cvsmapfs/

MAINTAINER=	rip@pinetec.co.za
COMMENT=	Helps keep track of modes and permissions of files in cvs

EXTRACT_CMD=	${CAT}	# despite .tar.gz suffix, only tarball
EXTRACT_BEFORE_ARGS=
USE_PERL5=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

do-install:
	$(INSTALL_SCRIPT) $(WRKSRC)/cvsmapfs $(PREFIX)/bin/cvsmapfs

post-install:
.if !defined(NOPORTDOCS)
	$(MKDIR) $(PREFIX)/share/doc/cvsmapfs
	$(INSTALL_DATA) $(WRKSRC)/README $(PREFIX)/share/doc/cvsmapfs
.endif

.include <bsd.port.mk>
