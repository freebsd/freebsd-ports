# $FreeBSD$

PORTNAME=	creduce
#PORTVERSION=	2.0.1
DISTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	http://embed.cs.utah.edu/creduce/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Produces small test cases

LICENSE=	BSD

BUILD_DEPENDS=	clang32=3.2:${PORTSDIR}/lang/clang32
RUN_DEPENDS=	clang32=3.2:${PORTSDIR}/lang/clang32
RUN_DEPENDS=	topformflat:${PORTSDIR}/devel/delta \
		astyle:${PORTSDIR}/devel/astyle \
		p5-Benchmark-Timer>=0:${PORTSDIR}/devel/p5-Benchmark-Timer \
		p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common

USE_GITHUB=	yes
GH_ACCOUNT=	csmith-project
GH_TAGNAME=	a2422d5
GH_COMMIT=	a2422d5

GNU_CONFIGURE=	yes
CONFIGURE_FLAGS=	--with-llvm=${LOCALBASE}

USES=	gmake perl5

post-patch:
	${REINPLACE_CMD} 's,llvm-config,llvm-config32,g' ${WRKSRC}/configure

.include <bsd.port.mk>
