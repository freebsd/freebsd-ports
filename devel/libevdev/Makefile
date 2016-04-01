# $FreeBSD$

PORTNAME=	libevdev
PORTVERSION=	1.4.4
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Linux Event Device library

LICENSE=	MIT # without linux/*.h
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:multimedia/v4l_compat
RUN_DEPENDS=	v4l_compat>=1.0.20110603:multimedia/v4l_compat

USES=		gmake libtool pathfix python:build tar:xz
EXTRACT_AFTER_ARGS=	--exclude include # v4l_compat
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_DOXYGEN=""
CPPFLAGS+=	-I${LOCALBASE}/include # v4l_compat
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/input\.h/s,top_srcdir,LOCALBASE,' \
		${WRKSRC}/libevdev/Makefile.in
# XXX tools require signalfd(2), test require /dev/uinput
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,tools test,,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
