# $FreeBSD$

PORTNAME=	xmmsctrl
PORTVERSION=	1.8
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://user.it.uu.se/~adavid/utils/ \
		http://distro.ibiblio.org/pub/linux/distributions/pdaxrom/src/ \
		http://ftp.nluug.nl/os/Linux/distr/pdaxrom/src/ \
		http://www.sourcefiles.org/Multimedia/MP3/Tools/Miscellaneous/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Small utility to control XMMS from the command line

LICENSE=	GPLv2

BUILD_DEPENDS=	xmms:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms

USES=		gmake
USE_CSTD=	gnu89

PORTDOCS=	Changelog README

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${INSTALL_DATA} emacs-transcriber twmrc_bindings \
			${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_SCRIPT} *.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
