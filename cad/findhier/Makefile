# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	findhier
PORTVERSION=	1.14
CATEGORIES=	cad
MASTER_SITES=	http://www.iclab.snu.ac.kr/~chilly/Work/CAD/
DISTNAME=	fh${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Hierarchy Viewer for magic/CIF/GDSII/PCSTR/GED/TeX

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/fh man/man1/fh.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fh.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
