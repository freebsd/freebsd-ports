# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libexplain
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library which may be used to explain Unix and Linux system call errors

LICENSE=	LGPL3

RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof
BUILD_DEPENDS=	pdfopt:${PORTSDIR}/print/ghostscript9 \
		gsed:${PORTSDIR}/textproc/gsed

USE_AUTOTOOLS=	libtool
USES=		bison gettext gmake
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.include "Makefile.man"

post-patch:
	@${REINPLACE_CMD} -e 's|sed -e|gsed -e|g' -e 's|\ sed\ | gsed |g' \
		-e '/@sleep 1/d' \
			${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
