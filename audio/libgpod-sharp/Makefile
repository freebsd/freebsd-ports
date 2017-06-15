# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-sharp

MAINTAINER=	mono@FreeBSD.org
COMMENT=	.Net bindings for the libgpod library

RUN_DEPENDS=	${LOCALBASE}/lib/libgpod.so:audio/libgpod

OPTIONS_EXCLUDE=DOCS IMOBILE PYTHON
OPTIONS_SLAVE=	MONO

BUILD_WRKSRC=	${WRKSRC}/bindings/mono
INSTALL_WRKSRC=	${WRKSRC}/bindings/mono

SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../libgpod

PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
