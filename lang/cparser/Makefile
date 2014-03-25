# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	cparser
PORTVERSION=	0.9.14
CATEGORIES=	lang devel
MASTER_SITES=	SF

MAINTAINER=	sperber@FreeBSD.org
COMMENT=	C99 compiler using libFIRM as backend

LICENSE=	GPLv2

LIB_DEPENDS=	libfirm.so:${PORTSDIR}/devel/libfirm

USES=		pkgconfig gmake tar:bzip2

PLIST_FILES=	bin/cparser \
		man/man1/cparser.1.gz

BUILDDIR=	optimize

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
BUILDDIR=	debug
.else
post-patch:
	@${REINPLACE_CMD} -e 's/^variant  ?= debug/variant  ?= optimize/' \
		${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${BUILDDIR}/cparser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cparser.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
