PORTNAME=	tcbasic
DISTVERSION=	2.3.0
CATEGORIES=	lang
MASTER_SITES=	https://github.com/tcort/${PORTNAME}/archive/refs/tags/v${PORTVERSION}/

MAINTAINER=	linuxgeek@gmail.com
COMMENT=	Small BASIC Interpreter written in C
WWW=		https://github.com/tcort/tcbasic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake

PLIST_FILES=	bin/tcbasic share/man/man1/tcbasic.1.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE= EXAMPLES

do-install-EXAMPLES-on:
		@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/examples/*.bas ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
