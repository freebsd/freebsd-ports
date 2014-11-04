# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	1.2.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/python/ \
		ftp://libvirt.org/libvirt/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Python bindings for Libvirt virtualization API

LICENSE=	GPLv2

LIB_DEPENDS=	libvirt.so:${PORTSDIR}/devel/libvirt

USES=	pkgconfig python shebangfix
SHEBANG_FILES=	generator.py sanitytest.py setup.py
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|"python"|"${PYTHON_CMD}"|g' \
		${WRKSRC}/setup.py

post-install:
.for lib in libvirtmod libvirtmod_qemu libvirtmod_lxc
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/site-packages/${lib}.so
.endfor

.include <bsd.port.mk>
