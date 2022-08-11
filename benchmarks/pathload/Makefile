PORTNAME=	pathload
PORTVERSION=	1.3.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cc.gatech.edu/~dovrolis/bw-est/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Measurement tool for network path available bandwidth estimation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/pathload_rcv bin/pathload_snd

post-patch:
	@${REINPLACE_CMD} -e '/^int main/s/l_int32 argc/int argc/' \
		${WRKSRC}/pathload_rcv.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} pathload_rcv pathload_snd \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
