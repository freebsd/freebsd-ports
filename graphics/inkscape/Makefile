# New ports collection makefile for:	inkscape
# Date created:		17 Nov 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inkscape
PORTVERSION=	0.42
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program seeks to become a full featured open source SVG editor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gc.1:${PORTSDIR}/devel/boehm-gc \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell2
RUN_DEPENDS=	${SITE_PERL}/XML/XQL.pm:${PORTSDIR}/textproc/p5-XML-XQL

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprintui libxslt
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_GCC=	3.4
CONFIGURE_ARGS=	--with-popt \
		--with-gnome-print
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include -I${LOCALBASE} ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LOCALBASE} ${PTHREAD_LIBS}"

MAN1=		inkscape.1 inkview.1

patch-autotools:
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

post-install:
	${GZIP_CMD} ${PREFIX}/man/fr/man1/inkscape.1
	@-update-desktop-database

.include <bsd.port.mk>
