# New ports collection makefile for:	tarantool
# Date created:		2011-11-25
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	tarantool
PORTVERSION=	1.3.5
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/71705094/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Tarantool, is a high performance key/value storage server

LICENSE=	BSD

ONLY_FOR_ARCHS=	i386

USE_CMAKE=	yes
ARCH=		i386
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g' \
		${WRKSRC}/test/CMakeLists.txt
	@${RM} ${WRKSRC}/test/lib/server.py \
		${WRKSRC}/test/lib/silverbox.py \
		${WRKSRC}/test/lib/tarantool_admin.py \
		${WRKSRC}/test/lib/tarantool_feeder_server.py \
		${WRKSRC}/test/lib/tarantool_server.py \
		${WRKSRC}/test/lib/*.orig

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
