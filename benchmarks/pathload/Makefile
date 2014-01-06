# Created by: dikshie <dikshie@lapi.itb.ac.id>
# $FreeBSD$

PORTNAME=	pathload
PORTVERSION=	1.3.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cc.gatech.edu/fac/Constantinos.Dovrolis/
DISTNAME=	${PORTNAME}

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	Measurement tool for network path available bandwidth estimation

GNU_CONFIGURE=	yes
USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/pathload_rcv bin/pathload_snd

do-install:
.for f in pathload_rcv pathload_snd
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
