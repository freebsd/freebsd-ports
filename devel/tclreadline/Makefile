# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	tclreadline
PORTVERSION=	2.1.0
PORTREVISION=	3
CATEGORIES=	devel tcl
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GNU readline for TCL

USES+=		tcl
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MANN=		tclreadline.n

PLIST_SUB+=	VERSION="${PORTVERSION}"

CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-tcl-includes=${TCL_INCLUDEDIR}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} \
	    -e '/^#define MALLOC/d; /^#define FREE/d; s|MALLOC|malloc|g; s|FREE|free|g' \
	    ${WRKSRC}/tclreadline.c

.include <bsd.port.mk>
