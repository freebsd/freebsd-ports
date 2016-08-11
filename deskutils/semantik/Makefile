# $FreeBSD$

PORTNAME=	semantik
PORTVERSION=	0.9.4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://ftp.waf.io/pub/release/ \
		http://www.freehackers.org/~tnagy/release/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE mind mapping tool

LICENSE=	GPLv3

USE_KDE4=	kdelibs
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT4=	corelib gui linguist_build svg webkit xml \
		moc_build qmake_build uic_build
USES=		pkgconfig python:2 shebangfix tar:bzip2 waf \
		shared-mime-info
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}" \
		PATH="${KDE4_PREFIX}/bin:$$PATH" \
		WAF_HOME="${WRKSRC}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	DESTDIR="${STAGEDIR}"
USE_LDCONFIG=	yes

SHEBANG_FILES=	${WRKSRC}/src/templates/beamer/wscript \
		${WRKSRC}/src/templates/pdflatex/wscript

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-d \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${PORTVERSION}

.include <bsd.port.mk>
