# New ports collection makefile for:	 cooledit
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	cooledit
PORTVERSION=	3.17.8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/X/cooledit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of utilities, including a GUI editor

USE_XLIB=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
INSTALLS_SHLIB=	yes

MAN1=		cooledit.1 coolman.1 smalledit.1

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_GETTEXT ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_NEXT_LOOK)
CONFIGURE_ARGS+=	--enable-NeXT-look
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^PACKAGE_FORCE|#PACKAGE_FORGE|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|USE_INCLUDED_LIBINTL=no|g ; \
		 s|\\$${top_builddir}/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#undef HAVE_WCHAR_H||g ; \
		 s|#undef HAVE_DCGETTEXT||g' ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|m4 intl rxvt|m4 rxvt|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
