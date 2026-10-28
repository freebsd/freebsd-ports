PORTNAME=	tclreadline
DISTVERSIONPREFIX=v
DISTVERSION=	2.5.0
CATEGORIES=	devel tcl

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GNU readline for TCL
WWW=		https://tclreadline.sourceforge.net/

LICENSE=	BSD3CLAUSE

USES=		libtool tcl:tea readline

CONFIGURE_ARGS+=--with-tk=no
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	yes
TCL_PKG=	${PORTNAME}${DISTVERSION}
PLIST_SUB+=	DISTVERSION=${DISTVERSION} TCL_PKG=${TCL_PKG}

post-patch:
	@${RM} ${WRKSRC}/INSTALL

.include <bsd.port.mk>
