PORTNAME=	mixertui
DISTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	alfix86@gmail.com
COMMENT=	Audio Mixer with a Terminal User Interface
WWW=		https://gitlab.com/alfix/mixertui/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo2.so:devel/libsysctlmibinfo2

USES=	ncurses
USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_TAGNAME=	4d9092861f57bbb4a8e64d14b29ec6aaa1c9190f

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8

.include <bsd.port.mk>
