# $FreeBSD$

PORTNAME=	semantik
DISTVERSION=	1.2.0
CATEGORIES=	deskutils kde
MASTER_SITES=	https://waf.io/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mind mapping tool

LICENSE=	GPLv3

USES=		kde:5 pkgconfig python:3.6 qt:5 shebangfix tar:bzip2 waf \
		desktop-file-utils gettext shared-mime-info
USE_KDE=	auth config configwidgets coreaddons i18n iconthemes \
		kdelibs4support kio sonnet widgetsaddons xmlgui
USE_QT=		core dbus declarative gui location network printsupport \
		svg webchannel webengine widgets xml \
		buildtools_build qmake_build

CONFIGURE_ENV=	PATH="${KDE_PREFIX}/bin:$$PATH" \
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
