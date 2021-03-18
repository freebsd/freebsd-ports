# $FreeBSD$

PORTNAME=	semantik
DISTVERSION=	1.2.6
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
USE_QT=		core dbus declarative gui location network printsupport \
		svg webchannel webengine widgets xml \
		buildtools_build qmake_build

CONFIGURE_ENV=	PATH="${KDE_PREFIX}/bin:$$PATH" \
		WAF_HOME="${WRKSRC}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	DESTDIR="${STAGEDIR}"
USE_LDCONFIG=	yes

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
