# New ports collection makefile for:   cwtex
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	cwtex
PORTVERSION=	16.3
CATEGORIES=	chinese
MASTER_SITES=	ftp://192.192.110.1/cwtex/cwTeX_linux/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/cwtex/
DISTFILES=	cwtexmain.tgz cwtex_freebsd.tgz

MAINTAINER=	statue@freebsd.sinica.edu.tw

BUILD_DEPENDS=  latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}
NO_BUILD=	YES

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/addfont ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/cwbibtx ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/cwmkidx ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/cwtex ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tex2xtc ${PREFIX}/bin/
	${CP} -R ${WRKSRC}/texmf/ ${PREFIX}/share/texmf/
	${CAT} ${FILESDIR}/config.ps  >> ${PREFIX}/share/texmf/dvips/config/config.ps
	mktexlsr

.include <bsd.port.post.mk>
