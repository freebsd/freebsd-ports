# New ports collection makefile for:	OO2C
# Date created:				December 17, 1999
# Whom:					Oliver Breuninger <ob@seicom.NET>
#
# $FreeBSD$

PORTNAME=	oo2c
PORTVERSION=	2.1.10
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ooc
DISTNAME=	${PORTNAME}_32-${PORTVERSION}

MAINTAINER=	ob@breuninger.org
COMMENT=	Optimizing Oberon-2 compiler of University of Kaiserslautern, Germany

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

DOCSDIR=	lib/${PORTNAME}
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		oo2c.1 oob.1 ooef.1 oowhereis.1

# This distribution is for 32-bit platforms.  A separate 64 bit distribution is available.
ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
