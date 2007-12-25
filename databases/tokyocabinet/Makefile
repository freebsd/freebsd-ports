# New ports collection makefile for:	tokyocabinet
# Date created:		2007-12-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	tokyocabinet
PORTVERSION=	1.1.6
CATEGORIES=	databases
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	A modern implementation of DBM

CONFIGURE_ARGS=	--enable-off64
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		tcbmgr.1 tcbmttest.1 tcbtest.1 tchmgr.1 tchmttest.1 \
		tchtest.1 tcucodec.1 tcumttest.1 tcutest.1
MAN3=		tcbdb.3 tchdb.3 tcutil.3 tokyocabinet.3

# Because gnomehack use "(libdir)" and it doesn't work, we need to patch
# it manually.
post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
