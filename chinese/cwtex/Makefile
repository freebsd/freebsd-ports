# New ports collection makefile for:   cwtex
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	cwtex
PORTVERSION=	16.6
CATEGORIES=	chinese
MASTER_SITES=	ftp://192.192.110.1/cwtex/cwTeX_linux/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/cwtex/
DISTFILES=	cwtexmain.tgz cwtexbin-16.6.tgz
EXTRACT_ONLY=	# empty

MAINTAINER=	statue@freebsd.sinica.edu.tw

BUILD_DEPENDS=  latex:${PORTSDIR}/print/teTeX

NO_BUILD=	YES

.include <bsd.port.pre.mk>

do-install:
	${TAR} -xzf ${DISTDIR}/cwtexmain.tgz -C ${PREFIX}/share/
	${TAR} -xzf ${DISTDIR}/cwtexbin-16.6.tgz -C ${PREFIX}/bin/
	${CAT} ${FILESDIR}/config.ps  >> ${PREFIX}/share/texmf/dvips/config/config.ps
	mktexlsr

.include <bsd.port.post.mk>
