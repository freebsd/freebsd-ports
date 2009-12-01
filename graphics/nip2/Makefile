# New ports collection makefile for:	vips
# Date created:		19 December 2003
# Whom:			Lev Serebryakov <lev@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nip2
PORTVERSION=	7.14.5
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Graphical user interface for VIPS

LIB_DEPENDS=	vips:${PORTSDIR}/graphics/vips	\
		gsl:${PORTSDIR}/math/gsl	\
		xml2:${PORTSDIR}/textproc/libxml2

USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	gnomemimedata glib20 pkgconfig gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`
# This port has no man-pages. It installs a number of HTML files,
# which are available through the GUI's Help. For this reason, they
# are always installed, regardless of the NOPORTDOCS setting.
# The PDF version of the documentation is another story:
.if defined(NOPORTDOCS)
EXTRACT_AFTER_ARGS=|${TAR} -xpf - --exclude nipguide --exclude pdf
.endif
# Somehow vendor's configure misses these:
MAKE_ENV+=	UPDATE_MIME_DATABASE=update-mime-database	\
		UPDATE_DESKTOP_DATABASE=update-desktop-database

MAN1=		nip2.1

post-patch:
	${REINPLACE_CMD} -e 's, malkovich,,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|n_bytes|x_n_bytes|g' -e 's|text_size|x_text_size|g' \
		${WRKSRC}/src/gtkitementry.c

.include <bsd.port.mk>
