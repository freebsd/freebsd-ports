# Created by: Søren Straarup <xride@x12.dk>
# $FreeBSD$

PORTNAME=	twpsk
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.ibiblio.org/pub/linux/apps/ham/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Openmotif X psk31 client

USE_XORG=	xpm
USES=		motif

MAN1=		psk31.1

FILES_TO_PATCH=	Makefile psk31.1 twpskHelp user-twpsk/makefile \
				user-twpsk/savedir/makefile \
				user-twpsk/savedir/INSTALL \
				user-twpsk/twpskHelp \
				user/term-psk31.C \
				user-twpsk/twpsk.C \
				user-twpsk/twpskDiags.C \
				user-twpsk/savedir/twpsk.C \
				user-twpsk/savedir/twpskDiags.C \
				user-twpsk/savedir/twpskHelp
post-patch:
.for file in ${FILES_TO_PATCH}
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g;s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
