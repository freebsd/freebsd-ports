# $FreeBSD$

PORTNAME=	mixertui
DISTVERSION=	1.2
CATEGORIES=	audio

MAINTAINER=	alfix86@gmail.com
COMMENT=	Audio Mixer with a Terminal User Interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo2.so:devel/libsysctlmibinfo2

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	5a07331c1f3d8b3631b9b48366472ffba51b8eab

PLIST_FILES=	share/man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8

.include <bsd.port.mk>
