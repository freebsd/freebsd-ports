# ex:ts=8
# Ports collection makefile for:  celvis
# Date created:			  Thur Aug 15, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	celvis
PORTVERSION=	1.3
CATEGORIES=	chinese editors
MASTER_SITES=	ftp://ftp.edu.cn/pub/Chinese/
#
# switch to http://www.ifcss.org/ftp-pub/software/unix/editor/celvis-1.3.tar.gz
#	if the distfile becomes unfetchable again.  Note this ver is slightly
#	different.
DISTNAME=	celvis

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A vi/ex clone that speaks Chinese

MAN1=		celvis.1
MLINKS=		celvis.1 cvi.1

do-install:
	@# install target in celvis Makefile is not too good -- this is easier
	${INSTALL_PROGRAM} ${WRKSRC}/celvis ${WRKSRC}/virec ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/celvis ${PREFIX}/bin/cvi
	${INSTALL_MAN} ${FILESDIR}/celvis.1 ${PREFIX}/man/man1/celvis.1

.include <bsd.port.mk>
