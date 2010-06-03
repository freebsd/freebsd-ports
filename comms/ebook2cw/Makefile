# ports collection makefile for:	ebook2cw
# Date created:		17 July 2008
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	ebook2cw
PORTVERSION=	0.7.0
PORTREVISION?=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/ebook2cw/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Convert textfiles into cw as a mp3 file

LIB_DEPENDS=	mp3lame:${PORTSDIR}/audio/lame

MAN1=		ebook2cw.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'g \
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
