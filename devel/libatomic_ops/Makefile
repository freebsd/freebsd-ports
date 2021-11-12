# Created by: Stanislav Sedov <stas@FreeBSD.org>

PORTNAME=	libatomic_ops
PORTVERSION=	7.6.12
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Atomic operations access library

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		autoreconf cpe libtool pathfix
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ivmai

CPE_VENDOR=	libatomic_ops_project

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
