# $FreeBSD$

PORTNAME=	ebook2cw
PORTVERSION=	0.8.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/ebook2cw/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Convert text files into cw as an mp3 or ogg file

LICENSE=	GPLv2

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libvorbis.so:audio/libvorbis

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'g \
	     ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|'g \
	     ${WRKSRC}/Makefile
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ebook2cw ${STAGEDIR}${PREFIX}/bin/ebook2cw
	${INSTALL_DATA} ${WRKSRC}/ebook2cw.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for 	f in ebook2cw.conf isomap.txt utf8map.txt
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${EXAMPLESDIR}/$f
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
