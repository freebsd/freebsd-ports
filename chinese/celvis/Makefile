# ex:ts=8
# New ports collection makefile for:    celvis
# Version required:     1.3
# Date created:         Thur Aug 15, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	celvis
PKGNAME=	zh-celvis-1.3
CATEGORIES=	chinese editors
MASTER_SITES=	ftp://ftp.edu.cn/PUB/Chinese/
#
# switch to http://www.ifcss.org/ftp-pub/software/unix/editor/celvis-1.3.tar.gz
#	if the distfile becomes unfetchable again.  Note this ver is slightly
#	different.

MAINTAINER=     obrien@FreeBSD.org

MAN1=		celvis.1

do-install:
	@# install target in celvis Makefile is not too good -- this is easier
	${INSTALL_PROGRAM} ${WRKSRC}/celvis ${WRKSRC}/virec ${PREFIX}/bin
	ln -sf ${PREFIX}/bin/celvis ${PREFIX}/bin/cvi
	${INSTALL_MAN} ${FILESDIR}/celvis.1 ${PREFIX}/man/man1/celvis.1
.if !defined{NOMANCOMPRESS}
	ln -sf ${PREFIX}/man/man1/celvis.1.gz ${PREFIX}/man/man1/cvi.1.gz
.else
	ln -sf ${PREFIX}/man/man1/celvis.1 ${PREFIX}/man/man1/cvi.1
.endif

.include <bsd.port.mk>
