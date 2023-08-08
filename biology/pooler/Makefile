PORTNAME=		pooler
DISTVERSIONPREFIX=	v
DISTVERSION=		1.86
CATEGORIES=		biology

MAINTAINER=	ssb22@cam.ac.uk
COMMENT=	Optimise DNA sequencing primer-set combinations
WWW=		https://ssb22.user.srcf.net/pooler/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/LICENSE

USES=		desktop-file-utils
USE_GITHUB=	yes

GH_ACCOUNT=	ssb22
GH_PROJECT=	PrimerPooler

INSTALL_TARGET=	install-strip

WRKSRC_SUBDIR=	pooler
PLIST_FILES=	bin/pooler man/man1/pooler.1.gz share/applications/pooler.desktop

.if exists(/usr/include/omp.h)
CFLAGS+=	-fopenmp
.endif

.include <bsd.port.mk>
