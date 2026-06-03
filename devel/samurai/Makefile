PORTNAME=	samurai
DISTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/michaelforney/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Ninja-compatible build tool written in C
WWW=		https://github.com/michaelforney/samurai

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project

CFLAGS+=	-DHAVE_GETLOADAVG

PLIST_FILES=	bin/samu \
		share/man/man1/samu.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/samu.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.options.mk>

.if ${OPSYS}_${OSREL:R} == FreeBSD_13
CFLAGS+=	-D_XOPEN_SOURCE=700L
.endif

.include <bsd.port.mk>
