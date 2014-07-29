# Created by: alfred@FreeBSD.org
# $FreeBSD$

PORTNAME=	cvsdiff2patch
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/cvsdiff2patch/
DISTNAME=	cvsdiff2patch-${PORTVERSION}
USES=	tar:bzip2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn cvs diff output into patch input

PLIST_FILES=	bin/cvsdiff2patch

post-patch:
	@${REINPLACE_CMD} -e "s/NOMAN/NO_MAN/" ${WRKSRC}/Makefile

.include <bsd.port.mk>
