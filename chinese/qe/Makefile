# New ports collection makefile for:   qe
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	qe
PORTVERSION=	0.1.1
CATEGORIES=	chinese
MASTER_SITES=	http://www.cc.ncu.edu.tw/~center5/product/qe/ \
		http://freebsd.sinica.edu.tw/~statue/

MAINTAINER=	statue@freebsd.sinica.edu.tw

HAS_CONFIGURE= yes
USE_GMAKE=     yes

post-configure:
	@(cd ${WRKSRC} && \
	${PATCH} < ${FILESDIR}/post-patch-Makefile )

.include <bsd.port.mk>
