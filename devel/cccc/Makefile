# ex:ts=8
# New ports collection makefile for:	cccc
# Date created:				12 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		cccc
PORTVERSION=		2.1.1
PORTREVISION=	1
CATEGORIES=		devel textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c++
DISTNAME=		${PORTNAME}-${PORTVERSION}.src

MAINTAINER=		ports@FreeBSD.org
COMMENT=	C and C++ Code Counter

BUILD_DEPENDS=		antlr:${PORTSDIR}/devel/pccts \
			dlg:${PORTSDIR}/devel/pccts

WRKSRC=			${WRKDIR}/usr/local/src/cccc-2.1.1
USE_GMAKE=		yes
MAKEFILE=		makefile
MAKE_ENV=		OSTYPE=FreeBSD

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cccc ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/cccc
.for file in cccc_inf.dat cccc_met.dat cccc_tmt.dat cccc_ug.htm
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/cccc
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/cccc
	@ ${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/cccc

.include <bsd.port.mk>
