# Created by: Sebastian Yepes <esn@x123.info>
# $FreeBSD$

PORTNAME=	hamlib
PORTVERSION=	1.2.15.3
CATEGORIES=	comms hamradio
MASTER_SITES=	SF

MAINTAINER=	db@FreeBSD.org
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications

LICENSE=	LGPL20

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USES=		perl5 pkgconfig pathfix
USE_GNOME=	libxml2
USE_TCL=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	autoconf libtool libltdl
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-perl-binding \
		--enable-tcl-binding --with-tcl=${TCL_LIBDIR} \
		--with-python-binding --without-rigmatrix
PLIST_SUB=	VER=${PORTVERSION} TCL_VER=${TCL_VER}

post-patch:
	${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		-e 's|%%TCL_LIBDIR%%|${TCL_LIBDIR}/hamlib|g' \
		${WRKSRC}/bindings/Makefile.in
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/Makefile.in
post-build:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' \
		${STAGEDIR}${WRKSRC}/bindings/Hamlib-pl.mk

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/COPYING.LIB \
	${WRKSRC}/ChangeLog ${WRKSRC}/INSTALL ${WRKSRC}/LICENSE \
	${WRKSRC}/NEWS ${WRKSRC}/PLAN ${WRKSRC}/README \
	${WRKSRC}/README.betatester ${WRKSRC}/README.win32 \
	${WRKSRC}/THANKS
	@${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
