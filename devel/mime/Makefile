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

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${LN} -sf libmime.so.1 ${STAGEDIR}${PREFIX}/lib/libmime.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmime.so

.include <bsd.port.mk>
