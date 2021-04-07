PORTNAME=	ecpprog
DISTVERSION=	g20200725
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Driver for FTDI based JTAG probes, to program ECP5 FPGAs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libftdi1.so:devel/libftdi1

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	gregdavill
GH_TAGNAME=	2b3e8eaba8faae5ae175ccec36b31e67d24244f7

WRKSRC_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
