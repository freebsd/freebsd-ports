PORTNAME=	cheesecutter
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9-beta-3-25
DISTVERSIONSUFFIX=	-gdbe9a9d
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tracker for composing music for the C64 SID chip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

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

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 1400042)
MAKE_ARGS=	DLDFLAGS=-L=-Wl,-z,nostart-stop-gc
.endif

.include <bsd.port.post.mk>
