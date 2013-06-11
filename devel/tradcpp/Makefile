# $FreeBSD$

PORTNAME=	tradcpp
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/dholland/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Traditional (K&R-style) C preprocessor

LICENSE=	BSD

PLIST_FILES=	bin/tradcpp

post-patch:
	@${REINPLACE_CMD} 's/NOMAN/NO_MAN/' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
