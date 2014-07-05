# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nip2
PORTVERSION=	7.40.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Graphical user interface for VIPS

OPTIONS_DEFINE=	DOCS
LIB_DEPENDS=	libvips.so.38:${PORTSDIR}/graphics/vips \
		libgoffice-*.so:${PORTSDIR}/devel/goffice \
		libgsl.so:${PORTSDIR}/math/gsl \
		libgvc.so:${PORTSDIR}/graphics/graphviz \
		libxml2.so:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USES=		bison dos2unix gettext gmake pkgconfig
USE_GNOME=	gnomemimedata glib20 gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
CONFIGURE_ENV+=	XGETTEXT=${LOCALBASE}/bin/xgettext	\
		LIBGVC_LIBS="-L${LOCALBASE}/lib/graphviz -lgvc"	\
		LIBGVC_CFLAGS="-I${LOCALBASE}/include/graphviz"
DOS2UNIX_GLOB=	*.def
SUB_FILES=	run-nip2.sh
# This port has no man-pages. It installs a number of HTML files,
# which are available through the GUI's Help. For this reason, they
# are always installed, regardless of the DOCS setting.
# Somehow vendor's configure misses these:
MAKE_ENV+=	UPDATE_MIME_DATABASE=update-mime-database	\
		UPDATE_DESKTOP_DATABASE=update-desktop-database
MANCOMPRESSED=	no

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/run-nip2.sh \
	    ${STAGEDIR}/${PREFIX}/bin/

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
	    ${WRKSRC}/test/scripts/*

test check: build
	#
	# Checks currently require ImageMagick's convert to be available
	# and aren't enabled by default. They take a long time -- tail
	# the log-file:
	#	${WRKSRC}/test/test_all.sh.log
	#
	${GMAKE} -C ${WRKSRC} check

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
EXTRACT_AFTER_ARGS+=	--exclude nipguide.pdf --exclude pdf
.endif

.include <bsd.port.mk>
