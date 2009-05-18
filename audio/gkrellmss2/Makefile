# New ports collection makefile for:	gkrellmss
# Date Created:				Tue Feb  4 13:24:50 PST 2003
# Whom:					Lars Eggert <larse@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	gkrellmss
PORTVERSION=	2.6
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellmss/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plugin for GKrellM with a VU meter showing left/right channel audio

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
LIB_DEPENDS=	fftw3.5:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_XORG=	x11
USE_GNOME=	esound gtk20
USE_GMAKE=	yes
MAKE_ENV=	LOCALEDIR="${PREFIX}/share/locale"

PORTDOCS=	Changelog README Themes
PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmss.so \
		share/locale/ru/LC_MESSAGES/gkrellm-gkrellmss.mo

post-patch:
	@${REINPLACE_CMD} -e 's|= -O2|=|g ; \
		 s|= gcc|+=|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|PKG_LIBS|PKG_LIB|g' \
		-e "s|-lfftw3|-L${LOCALBASE}/lib &|g" ${WRKSRC}/src/configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/gkrellmss.so \
		${PREFIX}/libexec/gkrellm2/plugins/gkrellmss.so
	${INSTALL_DATA} ${WRKSRC}/po/ru.mo \
		${PREFIX}/share/locale/ru/LC_MESSAGES/gkrellm-gkrellmss.mo
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
