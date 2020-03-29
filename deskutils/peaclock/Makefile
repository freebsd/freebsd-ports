# $FreeBSD$

PORTNAME=	peaclock
DISTVERSION=	0.4.2
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Customizable clock, timer, and stopwatch for the terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		cmake compiler:c++17-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	octobanana

CXXFLAGS+=	-Wno-narrowing # https://github.com/octobanana/peaclock/issues/18

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
