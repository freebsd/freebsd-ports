PORTNAME=	dssim
DISTVERSION=	3.2.4
PORTREVISION=	25
CATEGORIES=	graphics
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image similarity comparison simulating human perception
WWW=		https://kornel.ski/dssim

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
