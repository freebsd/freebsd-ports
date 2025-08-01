PORTNAME=	libvirt
PORTVERSION=	11.6.0
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/python/ \
		ftp://libvirt.org/libvirt/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python bindings for Libvirt virtualization API
WWW=		https://libvirt.org/python.html

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvirt.so:devel/libvirt

USES=		cpe pkgconfig python shebangfix
CPE_VENDOR=	redhat
SHEBANG_FILES=	generator.py setup.py
USE_PYTHON=	distutils autoplist

post-install:
.for lib in libvirtmod libvirtmod_qemu libvirtmod_lxc
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/site-packages/${lib}*.so
.endfor

.include <bsd.port.mk>
