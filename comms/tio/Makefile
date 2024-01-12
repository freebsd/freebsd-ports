PORTNAME=	tio
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple TTY terminal I/O application
WWW=		https://tio.github.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libinih.so:devel/inih

USES=		meson pkgconfig tar:xz

OPTIONS_DEFINE=	BASH DOCS
OPTIONS_DEFAULT=	BASH
OPTIONS_SUB=	yes

BASH_MESON_ON=	-Dbashcompletiondir=${PREFIX}/etc/bash_completion.d
BASH_MESON_OFF=	-Dbashcompletiondir=no

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
