# New ports collection makefile for:	piklab
# Date created:		2007-11-19
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	piklab
PORTVERSION=	0.15.10
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/newest%20release/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE IDE for microcontroller development

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
USE_CMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		piklab-hex.1 piklab-prog.1 piklab.1x

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/install/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/install/s|share/man|man|' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.post.mk>
