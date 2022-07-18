PORTNAME=	tio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.45
CATEGORIES=	comms

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple TTY terminal I/O application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	benhoyt:inih:r55:inih/subprojects/libinih

OPTIONS_DEFINE=	BASH DOCS
OPTIONS_DEFAULT=	BASH
OPTIONS_SUB=	yes

BASH_MESON_ON=	-Dbashcompletiondir=${PREFIX}/etc/bash_completion.d
BASH_MESON_OFF=	-Dbashcompletiondir=no

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
