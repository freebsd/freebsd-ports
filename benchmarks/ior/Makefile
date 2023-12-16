PORTNAME=	ior
DISTVERSION=	3.3.0-20230112
PORTREVISION=	2
CATEGORIES=	benchmarks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IOR and mdtest, parallel IO storage benchmark
WWW=		https://github.com/hpc/ior

LICENSE=	GPLv2

USES=		autoreconf gmake localbase:ldflags mpi:mpich pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hpc
GH_TAGNAME=	24d5d41

GNU_CONFIGURE=	yes

TEST_TARGET=	check

PLIST_FILES=	bin/ior \
		bin/md-workbench \
		bin/mdtest \
		man/man1/mdtest.1.gz

post-install: # see https://github.com/hpc/ior/issues/454
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/libaiori.a \
		${STAGEDIR}${PREFIX}/share/USER_GUIDE

.include <bsd.port.mk>
