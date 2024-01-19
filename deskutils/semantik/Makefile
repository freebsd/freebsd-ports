PORTNAME=	semantik
DISTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	https://waf.io/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mind mapping tool
WWW=		https://waf.io/semantik.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils gettext kde:5 pkgconfig python qt:5 \
		shared-mime-info shebangfix tar:bzip2 waf
USE_KDE=	auth config configwidgets coreaddons i18n iconthemes \
		kdelibs4support kio sonnet widgetsaddons xmlgui
USE_LDCONFIG=	yes
USE_QT=		core dbus declarative gui location network printsupport \
		svg webchannel webengine widgets xml \
		buildtools:build qmake:build

SHEBANG_FILES=	src/templates/beamer/wscript \
		src/templates/pdflatex/wscript \
		src/filters/fvym.py \
		src/filters/kdissert.py \
		src/filters/main.py \
		src/filters/others.py \
		src/filters/semantik.py \
		src/sembind.py \
		waf \
		wscript

# Let the ports system handle gtk-update-icon-cache and shared-mime-info
MAKE_ARGS=	--nogtkicons \
		--nomimes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-d \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${PORTVERSION}
	${INSTALL_MAN} ${WRKSRC}/src/data/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
