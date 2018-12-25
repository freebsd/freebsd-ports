# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spc2it
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-14-gd4f165e
CATEGORIES=	audio converters

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert SPC files to IT (Impulse Tracker) files

LICENSE=	GPLv2

USES=		cmake:insource
USE_GITHUB=	yes

GH_ACCOUNT=	uyjulian

PLIST_FILES=	bin/spc2it man/man1/spc2it.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
