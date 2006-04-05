# New ports collection makefile for:	maude
# Date created:				25 Mar 2005
# Whom:				Rick van der Zwet <rick@wzoeterwoude.net>
#
# $FreeBSD$
#

PORTNAME=	maude
PORTVERSION=	2.2
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/current/
DISTNAME=	Maude-${PORTVERSION}

MAINTAINER=	rick@wzoeterwoude.net
COMMENT=	A high-performance reflective language

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	bdd:${PORTSDIR}/science/buddy \
		tecla:${PORTSDIR}/devel/libtecla \
		gmp:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${DATADIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Mixfix/main.cc

.include <bsd.port.mk>
