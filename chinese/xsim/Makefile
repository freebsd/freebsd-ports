# New ports collection makefile for:	xsim
# Date created:		30 Dec 2002
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xsim
PORTVERSION=	0.3.9.4
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

USE_REINPLACE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cn-locale=EUC

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' 
		${WRKSRC}/xsim/IMdkit/IMConn.c
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's,@prefix@/plugins,${DATADIR}/plugins,g' \
			-e 's,@prefix@/dat,${DATADIR}/dat,g' \
			-e 's,@prefix@/bin,${DATADIR}/bin,g'

post-install:
	@${LN} -s ${PREFIX}/share/xsim/bin/xsim ${PREFIX}/bin/xsim
	@cd ${WRKSRC} && make install-data
	@${SED} -e 's,%%X11BASE%%,${X11BASE},g' < ${PKGMESSAGE}

.include <bsd.port.mk>
