# Created by: Lars Eggert <larse@isi.edu>
# $FreeBSD$

PORTNAME=	gkrellmss
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellmss/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin with a VU meter showing left/right channel audio

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USES=		gmake
NO_STAGE=	yes
USE_XORG=	x11
USE_GNOME=	esound gtk20
MAKE_ENV=	LOCALEDIR="${PREFIX}/share/locale"

PORTDOCS=	Changelog README Themes
PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmss.so \
		share/locale/ru/LC_MESSAGES/gkrellm-gkrellmss.mo

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|= -O2|=|g ; \
		 s|= gcc|+=|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|PKG_LIBS|PKG_LIB|g ; \
		 s|-lfftw3|-L${LOCALBASE}/lib &|g' ${WRKSRC}/src/configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/gkrellmss.so \
		${PREFIX}/libexec/gkrellm2/plugins/gkrellmss.so
	${INSTALL_DATA} ${WRKSRC}/po/ru.mo \
		${PREFIX}/share/locale/ru/LC_MESSAGES/gkrellm-gkrellmss.mo
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
