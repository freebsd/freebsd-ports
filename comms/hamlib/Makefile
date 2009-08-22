# New ports collection makefile for:	hamlib
# Date created:			30 April 2003
# Whom:				Sebastian Yepes <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	hamlib
PORTVERSION=	1.2.9
CATEGORIES=	comms hamradio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_GNOME=	pkgconfig gnomehack libxml2
USE_PERL5=	yes
USE_TCL=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-perl-binding --with-python=${PYTHON_CMD} \
		--with-tcl=${TCL_LIBDIR} --with-tcl-binding \
		--with-python-binding --without-with-rigmatrix
PLIST_SUB=	VER=${PORTVERSION} TCL_VER=${TCL_VER}

MAN1=		rigctl.1 rigmem.1 rigswr.1 rotctl.1 rigsmtr.1
MAN8=		rpc.rigd.8 rpc.rotd.8 rigctld.8 rotctld.8

post-patch:
	${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		-e 's|%%TCL_LIBDIR%%|${TCL_LIBDIR}/hamlib|g' \
		${WRKSRC}/bindings/Makefile.in
post-build:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' \
		${WRKSRC}/bindings/Hamlib-pl.mk

.include <bsd.port.mk>
