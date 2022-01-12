# Created by: Sebastian Yepes <esn@x123.info>

PORTNAME=	hamlib
PORTVERSION=	4.4
CATEGORIES=	comms hamradio
MASTER_SITES=	SF

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications

LICENSE=	LGPL20

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		autoreconf gnome libtool:keepla localbase:ldflags pathfix perl5 pkgconfig python \
		readline shebangfix tcl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PERL5=	build run
USE_PYTHON=	py3kplist

# $TCL_INCLUDE_SPEC
SHEBANG_FILES=	bindings/perltest.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl-binding \
		--with-tcl-binding --with-tcl=${TCL_LIBDIR} \
		--with-libusb \
		--with-python-binding
CONFIGURE_ENV=	LIBUSB_LIBS="-lusb"
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
PLIST_SUB=	VER=${PORTVERSION} TCL_VER=${TCL_VER}
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|python3-config|${PYTHON_CMD}-config|g' \
		${WRKSRC}/macros/ax_python_devel.m4
post-build:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' \
		${STAGEDIR}${WRKSRC}/bindings/Hamlib-pl.mk

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/COPYING.LIB \
		${WRKSRC}/ChangeLog ${WRKSRC}/INSTALL ${WRKSRC}/LICENSE \
		${WRKSRC}/NEWS ${WRKSRC}/PLAN ${WRKSRC}/README \
		${WRKSRC}/README.betatester ${WRKSRC}/README.osx \
		${WRKSRC}/README.developer ${WRKSRC}/README.freqranges \
		${WRKSRC}/README.multicast ${WRKSRC}/THANKS
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
