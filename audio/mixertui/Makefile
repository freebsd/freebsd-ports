PORTNAME=	mixertui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5
CATEGORIES=	audio

MAINTAINER=	alfix86@gmail.com
COMMENT=	Audio Mixer with a Terminal User Interface
WWW=		https://gitlab.com/alfix/mixertui/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbsddialog.so:devel/bsddialog \
		libsysctlmibinfo2.so:devel/libsysctlmibinfo2

USES=		ncurses
USE_GITLAB=	yes
GL_ACCOUNT=	alfix

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
