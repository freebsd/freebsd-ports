# $FreeBSD$

PORTNAME=	uclcmd
PORTVERSION=	0.1
CATEGORIES=	devel

MAINTAINER=	xmj@chaot.net
COMMENT=	Command line tool for working with UCL config files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libucl.so:textproc/libucl

USE_GITHUB=	yes
GH_ACCOUNT=	allanjude
GH_TAGNAME=	0d336e9

USES=		pkgconfig
PLIST_FILES=	bin/uclcmd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
