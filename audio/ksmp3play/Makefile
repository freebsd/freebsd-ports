# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ksmp3play
PORTVERSION=	0.5.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based MP3 player

LIB_DEPENDS=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg

GNU_CONFIGURE=	yes
USES=	pathfix
NO_STAGE=	yes
USE_SDL=	sdl
NO_WRKSUBDIR=	yes

MAN1=		ksmp3play.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude "CVS" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
