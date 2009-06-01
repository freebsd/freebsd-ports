# New ports collection makefile for:	xsim
# Date created:		30 Dec 2002
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xsim
PORTVERSION=	0.3.9.4
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-data-freebsd-gb2312.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and fast GBK Chinese XIM server

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cn-locale=eucCN \
		--with-bdb-includes=${BDB_INCLUDE_DIR} \
		--with-bdb-libraries=${BDB_LIB_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message xsim.sh
USE_BDB=	40+

.include <bsd.port.pre.mk>

CFLAGS+=	-fPIC
.if ${OSVERSION} < 700000
MAKE_ARGS+=	gcclib=`${CXX} -print-file-name=libgcc_pic.a`
.else
MAKE_ARGS+=	gcclib=`${CXX} -print-file-name=libgcc_s.so`
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/xsim/IMdkit/IMConn.c
	@${FIND} ${WRKSRC} -name xsimrc.in -or -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -Ee 's,@prefix@/(plugins|dat|bin),${DATADIR}/\1,g'
	@${FIND} ${WRKSRC} ! -type d \
		-exec ${GREP} -q _CPP_BITS_IOSBASE_H '{}' \; \
		-exec ${REINPLACE_CMD} 's/#ifdef _CPP_BITS_IOSBASE_H/#if defined(_IOS_BASE_H) || defined(_CPP_BITS_IOSBASE_H)/g' '{}' \;
	${REINPLACE_CMD} "s/-O2/${CFLAGS}/g; s,/usr/local,${LOCALBASE},; s|s,@bdblib@,\$$bdblib,|s,@bdblib@,${BDB_LIB_CXX_NAME},|" ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKDIR}/xsim.sh ${PREFIX}/bin/xsim
	@${MKDIR} ${DATADIR}/dat
	@${CP} -R ${WRKDIR}/usr/local/xsim/dat/* ${DATADIR}/dat
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
