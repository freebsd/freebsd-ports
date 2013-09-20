# Created by: jmg
# $FreeBSD$

PORTNAME=	mime
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/

MAINTAINER=	as@bsdgroup.de
COMMENT=	C library to parse mime data

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,-fpic,-fpic -fPIC,g" ${WRKSRC}/Makefile.in

post-install:
	@(cd ${PREFIX}/lib ; ${LN} -sf libmime.so.1 libmime.so )

.include <bsd.port.mk>
