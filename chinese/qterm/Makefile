# New ports collection makefile for:   qterm
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	qterm
PORTVERSION=	0.2.0
CATEGORIES=	chinese
MASTER_SITES=	http://qterm.gnuchina.org/qterm-${PORTVERSION}/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/qterm/

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	QTerm is a BBS client in Unix

USE_QT_VER=	3
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/qterm/qtermtelnet.cpp

.include <bsd.port.mk>
