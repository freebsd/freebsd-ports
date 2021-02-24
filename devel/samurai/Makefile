# $FreeBSD$

PORTNAME=	samurai
DISTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/michaelforney/samurai/releases/download/${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Ninja-compatible build tool written in C

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

ALL_TARGET=	samu
PLIST_FILES=	bin/samu \
		share/man/man1/samu.1.gz

.include <bsd.port.mk>
