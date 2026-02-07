PORTNAME=	elliott-803
PORTVERSION=	0.1.18
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators

MAINTAINER=	bsd.hsw@gmail.com
COMMENT=	Emulator and compilers for Elliott 803 computer
WWW=		https://github.com/hxw/Elliott-803

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang ncurses
MAKE_ARGS+=	DATADIR="${DATADIR}" PREFIX="${PREFIX}" VERSION="${PKGVERSION}" MAN1_DIR="${STAGEDIR}/${PREFIX}/share/man/man1"
MAKE_ENV+=	LC_ALL=en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	hxw
GH_PROJECT=	Elliott-803

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

DOCS_USES=		tex
DOCS_USE=		tex=xetex:build,dvipsk:build,latex:build
DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/fonts/linuxlibertine/LinLibertine_Bd-4.1.5.otf:x11-fonts/linuxlibertine

.include <bsd.port.options.mk>

do-build-DOCS-on:
	cd ${WRKSRC} && ${SETENVI} ${MAKE_ENV} ${MAKE_CMD} DESTDIR="${STAGEDIR}/${PREFIX}/share/doc/${PORTNAME}" h-code-docs

.include <bsd.port.mk>
