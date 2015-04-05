# Created by: dikshie <dikshie@lapi.itb.ac.id>
# $FreeBSD$

PORTNAME=	pathload
PORTVERSION=	1.3.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cc.gatech.edu/fac/Constantinos.Dovrolis/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Measurement tool for network path available bandwidth estimation

BROKEN=		Unfetchable
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
.for f in pathload_rcv pathload_snd
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
