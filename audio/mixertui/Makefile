# $FreeBSD$

PORTNAME=	mixertui
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	alfix86@gmail.com
COMMENT=	Audio Mixer with a Terminal User Interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo2.so:devel/libsysctlmibinfo2

USES=		ncurses:port
USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	a3e268cd8dced956f4657c019465d0ae611a8fa5

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8

.include <bsd.port.mk>
