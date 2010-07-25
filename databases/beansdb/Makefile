# New ports collection makefile for:	beansdb
# Date created:		2010-03-27
# Whom:			Qing Feng <qingfeng@me.com>
#
# $FreeBSD$
#

PORTNAME=	beansdb
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	qingfeng@me.com
COMMENT=	Yet anonther distributed key-value storage system from Douban Inc

BUILD_DEPENDS=	tokyocabinet>=1.4.30:${PORTSDIR}/databases/tokyocabinet
LIB_DEPENDS=	tokyocabinet:${PORTSDIR}/databases/tokyocabinet \
		event-1.4:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes

MAN1=		beansdb.1
PLIST_FILES=	bin/beansdb bin/convert

post-patch:
	${REINPLACE_CMD} -e 's|#include <mcheck.h>||g' \
		${WRKSRC}/*.c
	${REINPLACE_CMD} -e 's|#include <mcheck.h>||g' \
		${WRKSRC}/tools/*.c

.include <bsd.port.mk>
