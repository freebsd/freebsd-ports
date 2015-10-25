# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bg5ps
PORTVERSION=	1.3.0p3
PORTREVISION=	2
CATEGORIES=	chinese print
MASTER_SITES=	http://ftp.jaist.ac.jp/pub/FreeBSD/distfiles/ \
		http://www.gtlib.gatech.edu/pub/FreeBSD/distfiles/
DISTNAME=	bg5ps-1.3.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Chinese-Big5/GB encoded files to Postscript, using TTF fonts

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
LIB_DEPENDS=	libttf.so:${PORTSDIR}/print/freetype

USES=		python
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share/fonts/ttf/,${PREFIX}/share/fonts/TrueType/,g' \
	    ${WRKSRC}/gb2312-bg5ps.conf ${WRKSRC}/bg5ps.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bg5ps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttf2psm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bg5ps.conf ${STAGEDIR}${PREFIX}/etc/bg5ps.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gb2312-bg5ps.conf ${STAGEDIR}${PREFIX}/etc/gb2312-bg5ps.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/netscape.ps ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/test.big5 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/test.gb2312 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/test.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
