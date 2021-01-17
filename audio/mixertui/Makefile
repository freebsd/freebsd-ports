# $FreeBSD$

PORTNAME=	mixertui
DISTVERSION=	1.4.1
CATEGORIES=	audio

MAINTAINER=	alfix86@gmail.com
COMMENT=	Audio Mixer with a Terminal User Interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo2.so:devel/libsysctlmibinfo2

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	26e4c85fe6afd7403bfd6596c1da9161de03f1b4

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8

.include <bsd.port.options.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1300079
USES+=          ncurses
.else
USES+=          ncurses:port
.endif

.include <bsd.port.mk>
