PORTNAME=	ebook2cw
DISTVERSION=	0.8.5
CATEGORIES=	comms hamradio
MASTER_SITES=	https://fkurz.net/ham/ebook2cw/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Convert text files into cw as an mp3 or ogg file
WWW=		https://fkurz.net/ham/ebook2cw.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		gettext

PIE_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'g \
	     ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|'g \
	     ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ebook2cw ${STAGEDIR}${PREFIX}/bin/ebook2cw
	${INSTALL_MAN} ${WRKSRC}/ebook2cw.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ebook2cw.conf isomap.txt utf8map.txt
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${EXAMPLESDIR}/$f
.endfor

.include <bsd.port.mk>
