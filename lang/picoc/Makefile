PORTNAME=	picoc
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	lang devel

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Very small C interpreter for scripting
WWW=		https://gitlab.com/zsaleeba/picoc

LICENSE=	BSD3CLAUSE

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_riscv64=	Fails to link: missing sbrk

USE_GITLAB=	yes
GL_ACCOUNT=	zsaleeba
GL_TAGNAME=	dc85a51e9211cfb644f0a85ea9546e15dc1141c3

USES=		cpe gmake readline
CPE_VENDOR=	${PORTNAME}_project

PLIST_FILES=	bin/picoc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${STAGEDIR}${PREFIX}/bin/picoc

.include <bsd.port.mk>
