# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icat
PORTVERSION=	0.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Displays images in 256-color capable terminals

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		dos2unix gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	atextor

CONFLICTS=	sleuthkit-[0-9]*

PLIST_FILES=	bin/icat \
		share/man/man1/icat.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
