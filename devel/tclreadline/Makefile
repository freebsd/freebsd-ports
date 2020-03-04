# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	tclreadline
PORTVERSION=	2.3.8
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	devel tcl

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GNU readline for TCL

LICENSE=	BSD3CLAUSE

USES=		autoreconf libtool tcl readline:port

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-tcl-includes=${TCL_INCLUDEDIR} \
		--with-readline-includes=${LOCALBASE}/include \
		--with-readline-library="-L${LOCALBASE}/lib -lreadline" \
		--with-tk=no \
		--enable-tclstub
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	yes
TCL_PKG=	${PORTNAME}${PORTVERSION}
PLIST_SUB+=	PORTVERSION=${PORTVERSION} TCL_PKG=${TCL_PKG}

post-patch:
	@${RM} ${WRKSRC}/INSTALL

.include <bsd.port.mk>
