# New ports collection makefile for:	mime
# Date created:				3 June 2000
# Whom:					jmg
#
# $FreeBSD$
#

PORTNAME=	mime
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library to parse mime data

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-fpic,-fpic -fPIC,g" ${WRKSRC}/Makefile.in

post-install:
	@(cd ${PREFIX}/lib ; ${LN} -sf libmime.so.1 libmime.so )

.include <bsd.port.mk>
