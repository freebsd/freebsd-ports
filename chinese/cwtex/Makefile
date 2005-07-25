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
DISTFILES=	cwtexmain.tgz cwtexbin-${PORTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CwTeX let you use Chinese Big5 codes in TeX/LaTeX documents

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}/share ${WRKSRC}/bin
	${TAR} -kxzf ${DISTDIR}/cwtexmain.tgz -C ${WRKSRC}/share
	${TAR} -kxzf ${DISTDIR}/cwtexbin-${PORTVERSION}.tgz -C ${WRKSRC}/bin

do-install:
	cd ${WRKSRC}/share && ${FIND} * \
		| ${CPIO} -dpum --quiet -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${CAT} ${FILESDIR}/config.ps >> ${PREFIX}/share/texmf/dvips/config/config.ps
	mktexlsr

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		"Does not install on ia64 or sparc64"
.endif

.include <bsd.port.post.mk>
