PORTNAME=	semantik
DISTVERSION=	1.2.7
CATEGORIES=	deskutils kde
MASTER_SITES=	https://waf.io/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mind mapping tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kde:5 pkgconfig python:3.6+ qt:5 shebangfix tar:bzip2 waf \
		desktop-file-utils gettext shared-mime-info
USE_KDE=	auth config configwidgets coreaddons i18n iconthemes \
		kdelibs4support kio sonnet widgetsaddons xmlgui
USE_LDCONFIG=	yes
USE_QT=		core dbus declarative gui location network printsupport \
		svg webchannel webengine widgets xml \
		buildtools_build qmake_build

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

CONFIGURE_ENV=	PATH="${KDE_PREFIX}/bin:$$PATH" \
		WAF_HOME="${WRKSRC}"
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
# Help WAF a bit more by simply adding the locations to the KF5
# headers ourselves...
CXXFLAGS+=	-I${LOCALBASE}/include/KF5/KAuthCore \
		-I${LOCALBASE}/include/KF5/KConfigCore \
		-I${LOCALBASE}/include/KF5/KConfigGui \
		-I${LOCALBASE}/include/KF5/KConfigWidgets \
		-I${LOCALBASE}/include/KF5/KCoreAddons \
		-I${LOCALBASE}/include/KF5/KDELibs4Support \
		-I${LOCALBASE}/include/KF5/KI18n \
		-I${LOCALBASE}/include/KF5/KIOCore \
		-I${LOCALBASE}/include/KF5/KIOWidgets \
		-I${LOCALBASE}/include/KF5/KWidgetsAddons \
		-I${LOCALBASE}/include/KF5/KXmlGui \
		-I${LOCALBASE}/include/KF5/SonnetUi \


PLIST_SUB=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's+@@LOCALBASE@@+${LOCALBASE}+' \
		${WRKSRC}/wscript

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/langs/ d' \
		${WRKSRC}/wscript

post-configure:
	# Waf injects some bizzarre 3- and 4-level ../ stacks into the include
	# paths, which don't match how KDE includes are organized, and in a
	# poudriere build don't necessarily reach /usr/local/include either.
	@${REINPLACE_CMD} -e "s+..PWD............/include+${LOCALBASE}/include+g" \
		${WRKSRC}/build/c4che/_cache.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-d \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${PORTVERSION}
	${INSTALL_MAN} ${WRKSRC}/src/data/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
