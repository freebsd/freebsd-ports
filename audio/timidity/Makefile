# New ports collection makefile for:    timidity
# Date created:         17 Nov 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	timidity
PORTVERSION=	0.2i
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/misc/hardware/soundcard/gus/ \
		http://www.goice.co.jp/member/mo/timidity/dist/
DISTFILES=	${TIINS} ${DISTNAME}.tar.gz
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	MIDI to WAV renderer and player

NO_CDROM=	"Uses copyrighted patches"

TIINS=		goemon.tgz
INSTALL_TARGET=	install.all
MAN1=		timidity.1

post-patch:
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/linux_a.c > ${WRKSRC}/linux_a.c.new
	@${MV} ${WRKSRC}/linux_a.c.new ${WRKSRC}/linux_a.c

post-install:
	cd ${PREFIX}/lib/timidity && \
	tar zxf ${DISTDIR}/${TIINS} && \
	${CP} goemon.cfg goemon.cfg.bak && \
	${SED} 's=dir goemon=dir ${PREFIX}/lib/timidity/goemon=' \
	   < goemon.cfg.bak > goemon.cfg && \
	${RM} goemon.cfg.bak

.include <bsd.port.mk>
