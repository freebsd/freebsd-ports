PORTNAME=	kexis
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Kexis/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless WAV file compressor

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/kexis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kexis ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
