PORTNAME=	libdpv
DISTVERSION=	0.20260629
CATEGORIES=	devel

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Dialog extension for progress tracking

LICENSE=	BSD2CLAUSE

IGNORE_FreeBSD_14=	FreeBSD 14 has libdpv in base

LIB_DEPENDS=	libcdialog.so:devel/cdialog \
		libfigpar.so:devel/libfigpar

USES=		uidfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	dpv

WRKSRC_SUBDIR=	lib/libdpv

.include <bsd.port.mk>
