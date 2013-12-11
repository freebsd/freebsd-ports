# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bg5ps
PORTVERSION=	1.3.0p3
CATEGORIES=	chinese print
MASTER_SITES=	http://ftp.jaist.ac.jp/pub/FreeBSD/distfiles/ \
		http://www.gtlib.gatech.edu/pub/FreeBSD/distfiles/
DISTNAME=	bg5ps-1.3.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Chinese-Big5/GB encoded files to Postscript, using TTF fonts

LIB_DEPENDS=	libttf.so:${PORTSDIR}/print/freetype

USE_PYTHON=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bg5ps ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttf2psm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bg5ps.conf ${PREFIX}/etc/bg5ps.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gb2312-bg5ps.conf ${PREFIX}/etc/gb2312-bg5ps.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/netscape.ps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/test.big5 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/test.gb2312 ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/test.sh ${EXAMPLESDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
