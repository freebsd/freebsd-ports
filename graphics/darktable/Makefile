# New ports collection makefile for:	darktable
# Date created:				11 March 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darktable
PORTVERSION=	0.7.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.7

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

LIB_DEPENDS=	exiv2.9:${PORTSDIR}/graphics/exiv2 \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		lensfun.2:${PORTSDIR}/graphics/lensfun \
		lcms.1:${PORTSDIR}/graphics/lcms \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		curl.6:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	libglade2 librsvg2 gconf2
GCONF_SCHEMAS=	${PORTNAME}.schemas
USE_SQLITE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-silent-rules --disable-gkeyring
INSTALLS_ICONS=	yes
MAN1=		${PORTNAME}.1

post-patch:
# BSD readlink(1) is incompatible with one from GNU coreutils
	@${REINPLACE_CMD} -e 's,readlink -f,realpath,' \
		${WRKSRC}/tools/create_version_h.sh
# Adjust location of `gnome-keyring.h' header file
	@${REINPLACE_CMD} -e 's,gnome-keyring\.h,gnome-keyring-1/&,' \
		${WRKSRC}/src/common/pwstorage/backend_gkeyring.c
# Remove `-g' from C[PP]FLAGS
	@${REINPLACE_CMD} -e 's, -g$$,,' \
		${WRKSRC}/src/LibRaw/Makefile.in \
		${WRKSRC}/src/iop/Makefile.in
	@${REINPLACE_CMD} -E 's,[[:blank:]]-g([^t]),\1,' \
		${WRKSRC}/src/imageio/format/Makefile.in \
		${WRKSRC}/src/imageio/storage/Makefile.in \
		${WRKSRC}/src/libs/Makefile.in \
		${WRKSRC}/src/iop/Makefile.in \
		${WRKSRC}/src/views/Makefile.in
# Drop `-Werror' to fix the build of `common/image.c' on i386
	@${REINPLACE_CMD} -e 's,-Werror ,,' ${WRKSRC}/src/Makefile.in
# Do not install useless documentation files
	@${REINPLACE_CMD} -e 's, install-dtdocDATA,,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
