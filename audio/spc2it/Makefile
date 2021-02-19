# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spc2it
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	audio converters

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert SPC files to IT (Impulse Tracker) files

LICENSE=	GPLv2

USES=		meson
USE_GITHUB=	yes

GH_ACCOUNT=	uyjulian

PLIST_FILES=	bin/spc2it \
		man/man1/spc2it.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${MESON_BUILD_DIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
