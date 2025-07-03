PORTNAME=	ztop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	filesystems sysutils

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Display ZFS dataset I/O in real time
WWW=		https://github.com/asomers/ztop

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	asomers

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
		${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
