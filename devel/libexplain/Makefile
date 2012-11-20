# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libexplain
PORTVERSION=	1.1
DISTVERSIONSUFFIX=	.D001
CATEGORIES=	devel
MASTER_SITES=	http://libexplain.sourceforge.net/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library which may be used to explain Unix and Linux system call errors

LICENSE=	LGPL3

RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof
BUILD_DEPENDS=	pdfopt:${PORTSDIR}/print/ghostscript9 \
		gsed:${PORTSDIR}/textproc/gsed

USE_AUTOTOOLS=	libtool
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>
.include "Makefile.man"

post-patch:
	${REINPLACE_CMD} -e "s|sed '|gsed '|g" -e 's|sleep 1|true|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
