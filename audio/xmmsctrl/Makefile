# New ports collection makefile for:	xmmsctrl
# Date created:				22 September 2005
# Whom:					Jason E. Hale <jhale@bluebottle.com>
#
# $FreeBSD$
#

PORTNAME=	xmmsctrl
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://user.it.uu.se/~adavid/utils/

MAINTAINER=	jhale@bluebottle.com
COMMENT=	A small utility to control XMMS from the command line

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PORTDOCS=	Changelog README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${INSTALL_DATA} emacs-transcriber twmrc_bindings \
			${EXAMPLESDIR} && \
		${INSTALL_SCRIPT} *.sh ${EXAMPLESDIR}

.include <bsd.port.mk>
