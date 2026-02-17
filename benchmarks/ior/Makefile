PORTNAME=	ior
DISTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IOR and mdtest, parallel IO storage benchmark
WWW=		https://github.com/hpc/ior

LICENSE=	GPLv2

USES=		autoreconf gmake localbase:ldflags mpi:mpich pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hpc

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

TEST_TARGET=	check

PLIST_FILES=	bin/ior \
		bin/md-workbench \
		bin/mdtest \
		share/man/man1/mdtest.1.gz

post-install: # see https://github.com/hpc/ior/issues/454
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/libaiori.a \
		${STAGEDIR}${PREFIX}/share/USER_GUIDE

.include <bsd.port.mk>
