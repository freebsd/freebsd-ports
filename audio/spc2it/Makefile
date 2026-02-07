PORTNAME=	spc2it
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	audio converters

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert SPC files to IT (Impulse Tracker) files
WWW=		https://github.com/uyjulian/spc2it

LICENSE=	GPLv2

USES=		meson
USE_GITHUB=	yes

GH_ACCOUNT=	uyjulian

PLIST_FILES=	bin/spc2it \
		share/man/man1/spc2it.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${MESON_BUILD_DIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
