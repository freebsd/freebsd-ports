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
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-data-freebsd-gb2312.tar.gz

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

USE_REINPLACE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cn-locale=EUC

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=         "Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/xsim/IMdkit/IMConn.c
	@${FIND} ${WRKSRC} -name xsimrc.in -or -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -Ee 's,@prefix@/(plugins|dat|bin),${DATADIR}/\1,g'

post-install:
	@${LN} -s ${DATADIR}/bin/xsim ${PREFIX}/bin/xsim
	@${MKDIR} ${DATADIR}/dat
	@${CP} -R ${WRKDIR}/usr/local/xsim/dat/* ${DATADIR}/dat
	@${SED} -e 's,%%X11BASE%%,${X11BASE},g' < ${PKGMESSAGE}

.include <bsd.port.post.mk>
