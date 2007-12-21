# New ports collection makefile for:	maude
# Date created:				25 Mar 2005
# Whom:				Rick van der Zwet <rick@wzoeterwoude.net>
#
# $FreeBSD$
#

PORTNAME=	maude
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/versions/${PORTVERSION}/
DISTNAME=	Maude-${PORTVERSION}

MAINTAINER=	rick@wzoeterwoude.net
COMMENT=	A high-performance reflective language

LIB_DEPENDS=	bdd:${PORTSDIR}/science/buddy \
		tecla:${PORTSDIR}/devel/libtecla \
		gmp:${PORTSDIR}/math/libgmp4

USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${DATADIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Mixfix/main.cc

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		does not compile on 4.X or 5.X
.elif ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
