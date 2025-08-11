PORTNAME=	tclreadline
DISTVERSIONPREFIX=v
DISTVERSION=	2.4.0
CATEGORIES=	devel tcl

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GNU readline for TCL
WWW=		https://tclreadline.sourceforge.net/

LICENSE=	BSD3CLAUSE

USES=		autoreconf libtool tcl readline

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
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
TCL_PKG=	${PORTNAME}${DISTVERSION}
PLIST_SUB+=	DISTVERSION=${DISTVERSION} TCL_PKG=${TCL_PKG}

PORTSCOUT=	skipv:2.4.1

post-patch:
	@${RM} ${WRKSRC}/INSTALL

.include <bsd.port.mk>
