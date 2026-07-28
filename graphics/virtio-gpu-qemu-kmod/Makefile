PORTNAME=	virtio-gpu-qemu-kmod
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	graphics

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	VirtIO GPU driver for QEMU/UTM guests with framebuffer mmap
WWW=		https://gitlab.com/tgasiba/virtio_gpu_qemu

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only tested on aarch64 and amd64 guests

USES=		kmod uidfix

USE_GITLAB=	yes
GL_ACCOUNT=	tgasiba
GL_PROJECT=	virtio_gpu_qemu

MAKE_ARGS=	SYSDIR=${SRC_BASE}/sys

SUB_FILES=	pkg-message

PLIST_FILES=	${KMODDIR}/virtio_gpu_qemu.ko \
		share/examples/virtio_gpu_qemu/loader.conf.sample \
		share/man/man4/virtio_gpu_qemu.4.gz \
		share/X11/xorg.conf.d/20-virtio-gpu-qemu.conf

.include <bsd.port.mk>
