# Created by: jraynard
# $FreeBSD$

PORTNAME=	electricfence
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/misc
DISTNAME=	ElectricFence-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Debugging malloc() that uses the VM hardware to detect buffer overruns

USE_LDCONFIG=	yes
CFLAGS+=	-D__USE_BSD
MAN3=		efence.3

MAKE_ARGS=	CC="${CC}"
PLIST_FILES=	bin/ef.sh lib/libefence.a lib/libefence.so.0

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libefence.so.0.0 ${PREFIX}/lib/libefence.so.0
	${INSTALL_SCRIPT} ${WRKSRC}/ef.sh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/efence.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
