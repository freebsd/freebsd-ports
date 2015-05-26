# Created by: joseph@randomnetworks.com
# $FreeBSD$

PORTNAME=	e3
PORTVERSION=	2.8
PORTEPOCH=	3
CATEGORIES=	editors
MASTER_SITES=	http://sites.google.com/site/e3editor/Home/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full featured text editor written in assembler

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

BROKEN=		does not fetch (certificate verification failed)

USES=		gmake tar:tgz
MAKE_ARGS=	OS=FREEBSD
ONLY_FOR_ARCHS=	i386

FETCH_ARGS=	-p -o ${DISTDIR}/${DISTFILES}

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
		${FETCH_CMD} ${MASTER_SITES}${DISTFILES}?attredirects=0\&d=1 ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e '/SYS_sigaction	46/s/46/342/' ${WRKSRC}/e3.h

.include <bsd.port.mk>
