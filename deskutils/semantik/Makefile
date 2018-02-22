# $FreeBSD$

PORTNAME=	semantik
DISTVERSION=	0.9.5
PORTREVISION=	4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://ftp.waf.io/pub/release/ \
		http://www.freehackers.org/~tnagy/release/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE mind mapping tool

LICENSE=	GPLv3

USES=		kde:4 pkgconfig python:2.7 shebangfix tar:bzip2 waf \
		gettext shared-mime-info
USE_KDE=	kdelibs
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT4=	corelib gui linguist_build svg webkit xml \
		moc_build qmake_build uic_build
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}" \
		PATH="${KDE_PREFIX}/bin:$$PATH" \
		WAF_HOME="${WRKSRC}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	DESTDIR="${STAGEDIR}"
USE_LDCONFIG=	yes

SHEBANG_FILES=	${WRKSRC}/src/templates/beamer/wscript \
		${WRKSRC}/src/templates/pdflatex/wscript \
		waf

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

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
	${INSTALL_MAN} ${WRKSRC}/src/data/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
