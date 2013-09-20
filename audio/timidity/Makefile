# $FreeBSD$

PORTNAME=	timidity
PORTVERSION=	0.2i
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.onicos.com/staff/iz/timidity/dist/:timidity	\
		http://www.anime.net/~goemon/timidity/:tiins
DISTFILES=	${TIINS}:tiins ${DISTNAME}.tar.gz:timidity
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	MIDI to PCM software synthesizer

CONFLICTS=	timidity++-2.13.*

TIINS=		goemon.tgz
INSTALL_TARGET=	install.all
MAN1=		timidity.1
NO_STAGE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,machine/soundcard.h,sys/soundcard.h,' \
		${WRKSRC}/linux_a.c

post-install:
	cd ${PREFIX}/lib/timidity && \
	${TAR} --no-same-owner --no-same-permissions -zxf ${DISTDIR}/${TIINS} && \
	${REINPLACE_CMD} -i "" -e 's,dir goemon,dir ${PREFIX}/lib/timidity/goemon,' \
		goemon.cfg

.include <bsd.port.mk>
