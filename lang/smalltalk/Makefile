# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Smalltalk

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--disable-gtk --without-emacs --without-gmp

MAN1=		gst.1
INFO=		gst gst-base gst-libs

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITH_TCLTK)
LIB_DEPENDS+=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
			--with-tk=${LOCALBASE}/lib/tk8.4
PLIST_SUB+=	TCLTK=""
.else
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=	TCLTK="@comment "
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e \
		's|-release $$(VERSION)|-avoid-version|g'
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/examples/gdbm.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.el ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
