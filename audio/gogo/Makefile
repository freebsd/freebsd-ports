# Created by: Yukihiro Nakai <Nacai@iname.com>
# $FreeBSD$

PORTNAME=	gogo
PORTVERSION=	3.13
CATEGORIES=	audio
MASTER_SITES=	http://homepage2.nifty.com/kei-i/petit/
DISTNAME=	petit313
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very fast MP3 encoder using recent x86 processors' features

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

# More than version 0.98
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

RESTRICTED=	Condition is not clear
ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-fomit-frame-pointer -ffast-math -funroll-loops

PORTDOCS=	cdda2mp3.gogo.en cdda2mp3.gogo.ja
PLIST_FILES=	bin/cdda2mp3.gogo bin/gogo

post-extract:
	@${TOUCH} ${WRKSRC}/readme.txt

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s| -pipe| $${CFLAGS}|g ; \
		 s|^CFLAGS|#CFLAGS|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cdda2mp3/cdda2mp3.bsd \
		${PREFIX}/bin/cdda2mp3.gogo
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/cdda2mp3/cdda2mp3.txt \
		${DOCSDIR}/cdda2mp3.gogo.en
	${INSTALL_DATA} ${WRKSRC}/contrib/cdda2mp3/cdda2mp3.euc \
		${DOCSDIR}/cdda2mp3.gogo.ja
.endif

.include <bsd.port.mk>
