# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	memchan
PORTVERSION=	2.3
CATEGORIES=	devel tcl
MASTER_SITES=	SF
PKGNAMEPREFIX=	tcl-
DISTNAME=	Memchan${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Two new channel types for in-memory channels in TCL8

BUILD_DEPENDS=	${LOCALBASE}/lib/tcllib/doctools/pkgIndex.tcl:${PORTSDIR}/devel/tcllib

WRKSRC=		${WRKDIR}/${DISTNAME}

MAKE_JOBS_SAFE=	yes
ALL_TARGET=	binaries libraries doc-old

USE_TCL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

# Too bad, n is no longer an acceptable section for bsd.man.mk
MANN=		fifo.n fifo2.n memchan.n memchanapi.n null.n random.n zero.n
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

regression-test test:
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
