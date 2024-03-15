PORTNAME=	e3
PORTVERSION=	2.8
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	editors
MASTER_SITES=	http://sites.google.com/site/e3editor/Home/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full featured text editor written in assembler
WWW=		http://www.sax.de/~adlibit/

BUILD_DEPENDS=	nasm:devel/nasm

ONLY_FOR_ARCHS=	i386
USES=		gmake tar:tgz
MAKE_ARGS=	OS=FREEBSD

post-patch:
	@${REINPLACE_CMD} -e '/SYS_sigaction	46/s/46/342/' ${WRKSRC}/e3.h

.include <bsd.port.mk>
