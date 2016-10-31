# $FreeBSD$

PORTNAME=	libpgf
PORTVERSION=	7.15.32
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-latest/ \
		SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	libPGF-codec-and-console-src

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Progressive Graphics Format (PGF) library

LICENSE=	LGPL21

USES=		autoreconf dos2unix libtool pathfix zip
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	configure.ac
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/PGF/Codec

.include <bsd.port.mk>
