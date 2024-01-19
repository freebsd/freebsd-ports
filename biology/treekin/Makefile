PORTNAME=	treekin
DISTVERSION=	0.5.1
PORTREVISION=	5
CATEGORIES=	biology
MASTER_SITES=	https://www.tbi.univie.ac.at/RNA/packages/source/
DISTNAME=	Treekin-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient computation of RNA folding dynamics
WWW=		https://www.tbi.univie.ac.at/RNA/Treekin/

LICENSE=	LatticeLib
LICENSE_NAME=	LatticeLib Disclaimer and Copyright
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

BUILD_DEPENDS=	lapacke>0:math/lapacke

USES=		blaslapack:netlib compiler:c++11-lang fortran gmake \
		localbase:ldflags

GNU_CONFIGURE=	yes

BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
