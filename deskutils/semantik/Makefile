# $FreeBSD$

PORTNAME=	semantik
PORTVERSION=	0.8.4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE mind mapping tool

LICENSE=	GPLv3

USE_KDE4=	kdehier kdelibs kdeprefix
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_PYTHON=	2.5+
USE_QT4=	corelib gui linguist_build svg webkit xml \
		moc_build qmake_build uic_build
USES=		pkgconfig shebangfix
USE_BZIP2=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}" \
		PATH="${KDE4_PREFIX}/bin:$$PATH" \
		WAF_HOME="${WRKSRC}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	DESTDIR="${STAGEDIR}"
USE_LDCONFIG=	yes

SHEBANG_FILES=	${WRKSRC}/src/templates/beamer/wscript \
		${WRKSRC}/src/templates/pdflatex/wscript
python_CMD=	${PYTHON_CMD}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/kde-config/kde4-config/g' \
		${WRKSRC}/wscript
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/langs/ d' \
		${WRKSRC}/wscript
.endif

do-configure:
	@cd ${WRKSRC}; \
		${SETENV} ${CONFIGURE_ENV} ./waf configure --prefix=${PREFIX}

do-build:
	@cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ./waf build ${_MAKE_JOBS}

do-install:
	@cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ./waf install
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
