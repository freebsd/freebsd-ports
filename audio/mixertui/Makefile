# $FreeBSD$

PORTNAME=	mixertui
DISTVERSION=	0.1
CATEGORIES=	audio

MAINTAINER=	alfix86@gmail.com
COMMENT=	Audio Mixer with a Terminal User Interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	12c04d4dc9722a5d8ebfc9e676475a3b1ed095d0

PLIST_FILES=	man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
