# New ports collection makefile for:   qe
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	qe
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://www.cc.ncu.edu.tw/~center5/product/qe/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/qe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QE is a PE2-like editor program under U*nix

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-configure:
	@${REINPLACE_CMD} -e '49s,-s,,' ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
