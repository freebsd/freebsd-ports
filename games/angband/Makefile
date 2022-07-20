PORTNAME=	angband
DISTVERSION=	4.2.2
DISTNAME=	Angband-${DISTVERSION}
CATEGORIES=	games
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Rogue-like game with color, X11 support

LICENSE=	GPLv2

USES=		autoreconf gmake ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_NCURSES_CONFIG=${TRUE}
CONFIGURE_ARGS=	--localstatedir=/var

CPPFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-Wl,--Bstatic -L${NCURSESLIB} -lncursesw -Wl,--Bdynamic

OPTIONS_DEFINE=	SDL X11 DOCS
OPTIONS_DEFAULT=X11

# The docs as shipped want to use theme "better", but that's
# not packaged in ports (yet); use rtd instead because it is.
DOCS_USES=		python:build
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

SDL_USES=		sdl
SDL_USE=		SDL=image,mixer,ttf,sdl
SDL_CONFIGURE_ENABLE=	sdl
X11_USES=		xorg
X11_USE=		XORG=ice,sm,x11
X11_RUN_DEPENDS=	xorg-fonts-miscbitmaps>=0:x11-fonts/xorg-fonts-miscbitmaps
X11_CONFIGURE_ENABLE=	x11

post-patch:
	@${REINPLACE_CMD} -e \
		'/-Wno-missing-field-initializers/,/fi$$/d ; \
		s|/games$$|/bin|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's|.SILENT:||' ${WRKSRC}/mk/buildsys.mk.in
	@${REINPLACE_CMD} -e \
		's|-O0||' ${WRKSRC}/src/Makefile

post-build-DOCS-on:
	# Needs gmake, although we could run sphinx directly
	cd ${WRKSRC}/docs && ${MAKE_CMD} singlehtml

post-stage-DOCS-on:
	mkdir -p ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/_build/singlehtml/index.html ${STAGEDIR}${DOCSDIR}/index.html

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/angband
.for i in user/save user/scores
	@${MKDIR} ${STAGEDIR}${DATADIR}/${i}
.endfor

.include <bsd.port.mk>
