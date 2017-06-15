# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$
#   $MCom: ports/devel/gnome-vfsmm/Makefile,v 1.31 2009/03/17 15:22:21 kwm Exp $

PORTNAME=	gnome-vfsmm
PORTVERSION=	2.26.0
PORTREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for gnomevfs2 library

BUILD_DEPENDS=	gm4:devel/m4

USES=		gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	glibmm gnomevfs2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples// ; \
		/^SUBDIRS =/s/docs//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
