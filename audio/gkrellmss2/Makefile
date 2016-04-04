# Created by: Lars Eggert <larse@isi.edu>
# $FreeBSD$

PORTNAME=	gkrellmss
PORTVERSION=	2.7
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellmss/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin with a VU meter showing left/right channel audio

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		gettext gmake
USE_XORG=	x11
USE_GNOME=	esound gtk20
MAKE_ENV=	LOCALEDIR="${PREFIX}/share/locale"

PORTDOCS=	Changelog README Themes
PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmss.so \
		share/locale/ru/LC_MESSAGES/gkrellm-gkrellmss.mo

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|= -O2|=|g ; \
		 s|= gcc|+=|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|PKG_LIBS|PKG_LIB|g ; \
		 s|-lfftw3|-L${LOCALBASE}/lib &|g' ${WRKSRC}/src/configure

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_LIB} ${WRKSRC}/src/gkrellmss.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins/gkrellmss.so
	${INSTALL_DATA} ${WRKSRC}/po/ru.mo \
		${STAGEDIR}${PREFIX}/share/locale/ru/LC_MESSAGES/gkrellm-gkrellmss.mo

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
