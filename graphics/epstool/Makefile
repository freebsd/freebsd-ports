# New ports collection makefile for:	epstool
# Version required:	1.06
# Date created:		23 October 1999
# Whom:			Yuzo FURUKAWA <hurukawa@kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	epstool-106
PKGNAME=	epstool-1.06
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/rjl/ \
		ftp://ftp.fh-koblenz.de/pub/Ghostscript/rjl/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55

MAKEFILE=	makefile.unx
WRKSRC=		${WRKDIR}/epstool

post-install:
	${MKDIR} ${PREFIX}/bin ${PREFIX}/share/doc/epstool
	${INSTALL_DATA} ${WRKSRC}/epstool.txt \
		${PREFIX}/share/doc/epstool/epstool.txt

.include <bsd.port.mk>
