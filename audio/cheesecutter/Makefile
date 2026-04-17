PORTNAME=	cheesecutter
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tracker for composing music for the C64 SID chip
WWW=		https://github.com/theyamo/CheeseCutter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	acme:devel/acme \
		ldc2:lang/ldc

USES=		desktop-file-utils gmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	theyamo
GH_PROJECT=	CheeseCutter
USE_SDL=	sdl2

MAKE_ARGS=	DLDFLAGS=-L=-Wl,-z,nostart-stop-gc
MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccutter ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ct2util ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/arch/fd/ccutter.desktop \
		${STAGEDIR}${DESKTOPDIR}/
	${INSTALL_DATA} ${WRKSRC}/icons/cc96.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/fr/man1
.for f in ccutter ct2util
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.fr.1 \
		${STAGEDIR}${PREFIX}/share/man/fr/man1/
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/example_tunes
	cd ${WRKSRC}/tunes && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/example_tunes

.include <bsd.port.mk>
