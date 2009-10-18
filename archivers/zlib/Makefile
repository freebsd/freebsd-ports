# New ports collection makefile for:	zlib
# Date created:		2009-10-18
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zlib
PORTVERSION=	1.2.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.zlib.net/ \
		http://www.gzip.org/zlib/

MAINTAINER=	skreuzer@exit2shell.com
COMMENT=	Delicately Unobtrusive Compression Library

HAS_CONFIGURE=	YES
USE_LDCONFIG=   YES

MAN3=		zlib.3

post-patch:
	@${REINPLACE_CMD} -e 's|%%MAN3PREFIX%%|${MAN3PREFIX}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
