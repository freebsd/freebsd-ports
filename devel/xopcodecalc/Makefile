PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	0.05
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical x86 CPU opcode calculator
WWW=		https://github.com/horsicq/XOpcodeCalc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		buildtools:build qmake:build core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	horsicq
GH_PROJECT=	XOpcodeCalc ${GH_SUBDIR}
GH_TAGNAME=	b3b2a0e:xaw 5c058a4:xo
GH_SUBDIR=	XAboutWidget:xaw XOptions:xo

post-extract:
	@${CHMOD} +x ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/release/xocalc \
		${STAGEDIR}${PREFIX}/bin
	cd ${INSTALL_WRKSRC}/LINUX && ${COPYTREE_SHARE} hicolor \
		${STAGEDIR}${PREFIX}/share/icons
	${SED} -e 's,#VERSION#,${PORTVERSION},' \
		${WRKSRC}/LINUX/xocalc.desktop \
		> ${STAGEDIR}${DESKTOPDIR}/xocalc.desktop

.include <bsd.port.mk>

PATCH_ARGS+=	-l
