PORTNAME=	kexis
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Kexis/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless WAV file compressor
WWW=		https://sourceforge.net/projects/kexis/

DEPRECATED=	Abandonware, niche format that never got any traction and no release in 18 years. Consider using audio/flac or audio/wavpack instead
EXPIRATION_DATE=2023-03-31

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/kexis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kexis ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
