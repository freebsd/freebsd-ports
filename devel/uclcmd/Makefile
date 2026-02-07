PORTNAME=	uclcmd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.20211204
CATEGORIES=	devel

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Command line tool for working with UCL config files
WWW=		https://github.com/allanjude/uclcmd/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libucl.so:textproc/libucl

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	allanjude

PLIST_FILES=	bin/uclcmd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
