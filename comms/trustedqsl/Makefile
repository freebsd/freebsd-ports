# $FreeBSD$

PORTNAME=	trustedqsl
PORTVERSION=	1.14.2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/TrustedQSL/v1.14.2/
DISTNAME=	tqsl-1.14.2

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook

LIB_DEPENDS=	db-5:${PORTSDIR}/databases/db5 \
		curl:${PORTSDIR}/ftp/curl

USES=		cmake
USE_WX=		2.8+
WX_UNICODE=	yes

MAN5=		trustedqsl.5

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} trustedqsl is now installed. You will have to create a directory .tqsl in
	@${ECHO_MSG} your home directory and setup a copy of ${PREFIX}/share/TrustedQSL/config.xml here
	@${ECHO_MSG} before this program will run correctly.
	@${ECHO_MSG}

.include <bsd.port.post.mk>
