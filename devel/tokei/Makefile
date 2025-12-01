PORTNAME=	tokei
DISTVERSIONPREFIX=	v
DISTVERSION=	13.0.0
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Display statistics about your code
WWW=		https://github.com/XAMPPRocky/tokei

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENCE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENCE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	XAMPPRocky

# enable all output serialization formats
CARGO_FEATURES=	all

PLIST_FILES=	bin/tokei

.include <bsd.port.mk>
