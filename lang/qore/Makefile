# Ports collection makefile for:	qore
# Date created:				12 November 2009
# Whom:					B. Estrade <estrabd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qore
PORTVERSION=	0.8.3
CATEGORIES=	lang
MASTER_SITES=	SF/qore/qore/${PORTVERSION}/

MAINTAINER=	estrabd@gmail.com
COMMENT=	The Qore Programming Language

LICENSE=	GPLv2

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre \
		xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison

LDFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"LEX=${LOCALBASE}/bin/flex"
CONFIGURE_ARGS=	--disable-debug --disable-static

MAN1=		qore.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
