# $FreeBSD$

PORTNAME=	libpgf
PORTVERSION=	6.14.12
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-latest/ \
		SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Progressive Graphics Format (PGF) library

LICENSE=	LGPL21

USES=		autoreconf dos2unix libtool
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	configure.ac
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
