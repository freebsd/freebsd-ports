# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	2.5.0
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/python/ \
		ftp://libvirt.org/libvirt/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python bindings for Libvirt virtualization API

LICENSE=	GPLv2

LIB_DEPENDS=	libvirt.so:devel/libvirt

USES=	pkgconfig python shebangfix
SHEBANG_FILES=	generator.py sanitytest.py setup.py
USE_PYTHON=	distutils autoplist

post-install:
.for lib in libvirtmod libvirtmod_qemu libvirtmod_lxc
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/site-packages/${lib}.so
.endfor

.include <bsd.port.mk>
