# $FreeBSD$

PORTNAME=	xmmsctrl
PORTVERSION=	1.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://user.it.uu.se/~adavid/utils/ \
		http://distro.ibiblio.org/pub/linux/distributions/pdaxrom/src/ \
		http://ftp.nluug.nl/os/Linux/distr/pdaxrom/src/ \
		http://www.sourcefiles.org/Multimedia/MP3/Tools/Miscellaneous/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Small utility to control XMMS from the command line

LICENSE=	GPLv2

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USES=		gmake
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PORTDOCS=	Changelog README

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${INSTALL_DATA} emacs-transcriber twmrc_bindings \
			${EXAMPLESDIR} && \
		${INSTALL_SCRIPT} *.sh ${EXAMPLESDIR}

.include <bsd.port.mk>
