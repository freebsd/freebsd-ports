# ports collection makefile for:	soundmodem
# Date created:		4 November 2006
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	soundmodem
PORTVERSION=	0.10
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.baycom.org/~tom/ham/soundmodem/ \
		http://chronos.org.uk/distfiles/

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio sound modem

LIB_DEPENDS=	audiofile:${PORTSDIR}/audio/libaudiofile

CONFIGURE_ARGS=	--disable-alsatest
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386
USE_GNOME=	gtk12 libxml
MAN8=		soundmodem.8 soundmodemconfig.8
PLIST_FILES=	bin/soundmodemconfig etc/rc.d/soundmodem \
		include/modem.h include/simd.h sbin/soundmodem

pre-patch:
	@${CP} ${FILESDIR}/soundmodem ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/soundcard/soundmodem.8 \
		${WRKSRC}/soundcard/main.c \
		${WRKSRC}/configapp/src/soundmodemconfig.8 \
		${WRKSRC}/configapp/src/main.c \
		${WRKSRC}/soundmodem

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/soundmodem ${PREFIX}/etc/rc.d

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
