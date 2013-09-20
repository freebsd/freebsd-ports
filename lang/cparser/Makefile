# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	cparser
PORTVERSION=	0.9.14
CATEGORIES=	lang devel
MASTER_SITES=	SF

MAINTAINER=	sperber@FreeBSD.org
COMMENT=	A C99 compiler using libFIRM as backend

LICENSE=	GPLv2

LIB_DEPENDS=	firm:${PORTSDIR}/devel/libfirm

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		pkgconfig

PLIST_FILES=	bin/cparser

MAN1=	cparser.1

BUILDDIR=	optimize
INSTALL_CMD=	${INSTALL_PROGRAM}

OPTIONS_DEFINE=	DEBUG

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
BUILDDIR=	debug
INSTALL_CMD=	${INSTALL_PROGRAM:S,-s,,}
.else
post-patch:
	@${REINPLACE_CMD} -e 's/^variant  ?= debug/variant  ?= optimize/' \
		${WRKSRC}/Makefile
.endif

do-install:
	@${INSTALL_CMD} ${WRKSRC}/build/${BUILDDIR}/cparser ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cparser.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
