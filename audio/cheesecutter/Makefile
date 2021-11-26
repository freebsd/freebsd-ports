# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	cheesecutter
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9-beta-3-25
DISTVERSIONSUFFIX=	-gdbe9a9d
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tracker for composing music for the C64 SID chip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_FreeBSD_14=	ld: error: undefined hidden symbol: __start___minfo

BUILD_DEPENDS=	acme:devel/acme \
		ldc2:lang/ldc

USES=		desktop-file-utils gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt
GH_PROJECT=	CheeseCutter

MAKEFILE=	Makefile.ldc
MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${MANPREFIX}/share/man/fr/man1 ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/arch/fd/ccutter.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/cc96.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.for f in ccutter ct2util
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.1 ${STAGEDIR}${MANPREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.fr.1 ${STAGEDIR}${MANPREFIX}/share/man/fr/man1
.endfor

.include <bsd.port.mk>
