# New ports collection makefile for:	OO2C
# Date created:				December 17, 1999
# Whom:					Oliver Breuninger <ob@seicom.NET>
#
# $FreeBSD$

PORTNAME=	oo2c
PORTVERSION=	1.5.2
CATEGORIES=	lang
MASTER_SITES=	http://www.uni-kl.de/OOC/files/oo2c/ \
		http://www.breuninger.org/files/distfiles/ \
		http://reality.sgi.com/boehm_mti/gc_source/
DISTNAME=	${PORTNAME}_32-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} gc4.14.tar.gz

MAINTAINER=	ob@breuninger.org
COMMENT=	Optimizing Oberon-2 compiler of University of Kaiserslautern, Germany

USE_LIBTOOL_VER=13
CONFIGURE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAN1=		oo2c.1 oob.1 ooef.1 oocn.1 oowhereis.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-extract:
	@${MV} ${WRKDIR}/gc    ${WRKSRC}/gc

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/oo2 ${PREFIX}/bin

.include <bsd.port.post.mk>
