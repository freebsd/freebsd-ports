# New ports collection makefile for:	ta-lib
# Date created:		Sun Jun 24 16:07:37 UTC 2007
# Whom:			Balwinder S "bsd" Dheeman <bsd@rubyforge.org>
#
# $FreeBSD$
#

PORTNAME=	ta-lib
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	bdheeman@hotmail.com
COMMENT=	A UNIX, POSIX Library for Technical Analysis

WRKSRC= 	${WRKDIR}/ta-lib

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^LIBTOOL[ ]*=.*|LIBTOOL=${LIBTOOL}|g'

.include <bsd.port.mk>
