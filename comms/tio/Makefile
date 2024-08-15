PORTNAME=	tio
DISTVERSION=	3.4
CATEGORIES=	comms
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/tio/tio/commit/
PATCHFILES=	c5afd86b9ae9757ebc465d6066e348bb7164f3c2.patch:-p1

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple TTY terminal I/O application
WWW=		https://tio.github.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnome lua:54 meson pkgconfig tar:xz
USE_GNOME=	glib20

OPTIONS_DEFINE=	BASH DOCS
OPTIONS_DEFAULT=BASH
OPTIONS_SUB=	yes

BASH_MESON_ON=	-Dbashcompletiondir=${PREFIX}/etc/bash_completion.d
BASH_MESON_OFF=	-Dbashcompletiondir=no

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
