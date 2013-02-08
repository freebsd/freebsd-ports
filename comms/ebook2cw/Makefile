# $FreeBSD$
#

PORTNAME=	ebook2cw
PORTVERSION=	0.8.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/ebook2cw/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Convert text files into cw as an mp3 or ogg file

LIB_DEPENDS=	mp3lame:${PORTSDIR}/audio/lame \
		vorbis:${PORTSDIR}/audio/libvorbis

MAN1=		ebook2cw.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'g \
	     ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|'g \
	     ${WRKSRC}/Makefile
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/ebook2cw ${PREFIX}/bin/ebook2cw
	@${INSTALL_DATA} ${WRKSRC}/ebook2cw.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for 	f in ebook2cw.conf isomap.txt utf8map.txt
	@${INSTALL_DATA} ${WRKSRC}/$f ${EXAMPLESDIR}/$f
.endfor
.endif
.if     !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
