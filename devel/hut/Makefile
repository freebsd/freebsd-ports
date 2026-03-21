PORTNAME=	hut
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	CLI tool for sr.ht
WWW=		https://git.sr.ht/~xenrox/hut

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		go:modules

GO_MODULE=	git.sr.ht/~xenrox/hut
GO_BUILDFLAGS=	-ldflags "-X 'main.version=${DISTVERSIONPREFIX}${PORTVERSION}'"

PLIST_FILES=	bin/hut \
		share/man/man1/${PORTNAME}.1.gz

post-build:
	@(cd ${WRKSRC}/doc && \
	${PREFIX}/bin/scdoc < ${PORTNAME}.1.scd > ${PORTNAME}.1)

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
