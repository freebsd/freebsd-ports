# ex:ts=8
# New ports collection makefile for: Electric Fence
# Date created: 	13 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	electricfence
PORTVERSION=	2.2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perens.com/pub/ElectricFence/Beta/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/misc
DISTNAME=	ElectricFence-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Debugging malloc() that uses the VM hardware to detect buffer overruns

INSTALLS_SHLIB=	yes
CFLAGS+=	-D__USE_BSD
MAN3=		efence.3

MAKE_ARGS=	CC="${CC}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libefence.so.0.0 ${PREFIX}/lib/libefence.so.0
	${INSTALL_SCRIPT} ${WRKSRC}/ef.sh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/efence.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
