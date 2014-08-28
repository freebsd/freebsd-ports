# Created by: David O'Brien (obrien@NUXI.org)
# $FreeBSD$

PORTNAME=	nwcc
PORTVERSION=	0.8.3
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Nils Weller's C compiler for Unix systems

ONLY_FOR_ARCHS=	i386 amd64

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--installprefix=${PREFIX}
ALL_TARGET=

post-patch:
	@${REINPLACE_CMD} -e 's|./nwcc|-./nwcc|' ${WRKSRC}/Makefile.skel

.include <bsd.port.mk>
