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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4

USE_REINPLACE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cn-locale=eucCN

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64 (missing -fPIC)"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/xsim/IMdkit/IMConn.c
	@${FIND} ${WRKSRC} -name xsimrc.in -or -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -Ee 's,@prefix@/(plugins|dat|bin),${DATADIR}/\1,g'
	@${FIND} ${WRKSRC} ! -type d \
		-exec ${GREP} -q _CPP_BITS_IOSBASE_H '{}' \; \
		-exec ${REINPLACE_CMD} 's/#ifdef _CPP_BITS_IOSBASE_H/#if defined(_IOS_BASE_H) || defined(_CPP_BITS_IOSBASE_H)/g' '{}' \;
	@${REINPLACE_CMD} "s/-O2/${CFLAGS}/g" ${WRKSRC}/configure

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" <${FILESDIR}/xsim.sh \
		>${PREFIX}/bin/xsim && ${CHMOD} 555 ${PREFIX}/bin/xsim
	@${MKDIR} ${DATADIR}/dat
	@${CP} -R ${WRKDIR}/usr/local/xsim/dat/* ${DATADIR}/dat
	@${SED} -e 's,%%X11BASE%%,${X11BASE},g' < ${PKGMESSAGE}

.include <bsd.port.post.mk>
