# ex:ts=8
# Ports collection makefile for:  cdecl
# Date created:			  Sat Sep 04, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	cdecl
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netsw.org/softeng/lang/c/tools/cdecl/  \
		ftp://ftp.cc.gatech.edu/ac121/linux/devel/lang/c/  \
		ftp://ftp.deva.net/pub/sources/programming/  \
		ftp://ftp.bitcon.no//pub/linux/linuxberg/files/console/dev/  \
		ftp://ftp.uakom.sk/pub/linux/devel/lang/c/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	${PORTNAME}
MAN1=		cdecl.1
MLINKS=		cdecl.1 c++decl.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${DOCSDIR}
.endif

.include <bsd.port.mk>
