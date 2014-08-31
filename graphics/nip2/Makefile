# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nip2
PORTVERSION=	7.40.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical user interface for VIPS

LICENSE=	GPLv2

BUILD_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils
LIB_DEPENDS=	libgoffice-*.so:${PORTSDIR}/devel/goffice \
		libgvc.so:${PORTSDIR}/graphics/graphviz \
		libvips.so:${PORTSDIR}/graphics/vips \
		libgsl.so:${PORTSDIR}/math/gsl
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USES=		bison desktop-file-utils dos2unix gettext gmake pkgconfig \
		shared-mime-info
DOS2UNIX_GLOB=	*.def
USE_GNOME=	gnomemimedata gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-desktop \
		--without-goffice

SUB_FILES=	run-nip2.sh

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/bin/bash|/bin/sh|' ${WRKSRC}/test/scripts/*

post-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} run-nip2.sh \
		${STAGEDIR}/${PREFIX}/bin)

test check: build
	#
	# Checks currently require ImageMagick's convert to be available
	# and aren't enabled by default. They take a long time -- tail
	# the log-file:
	#	${WRKSRC}/test/test_all.sh.log
	#
	(cd %{WRKSRC} && ${SETENV} {MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
