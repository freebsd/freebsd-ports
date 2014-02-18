# Created by: jmg
# $FreeBSD$

PORTNAME=	mime
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library to parse mime data

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	@(cd ${STAGEDIR}${PREFIX}/lib ; ${STRIP_CMD} libmime.so.1; \
		${LN} -sf libmime.so.1 libmime.so )

.include <bsd.port.mk>
