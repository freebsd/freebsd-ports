PORTNAME=	hamlib
PORTVERSION=	4.6.4
CATEGORIES=	comms hamradio
MASTER_SITES=	SF

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications
WWW=		https://sourceforge.net/projects/hamlib/

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
CONFIGURE_ENV=	LIBUSB_LIBS="-lusb" cf_with_cxx=yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
PLIST_SUB=	TCL_VER=${TCL_VER}
OPTIONS_DEFINE=	DOCS

post-build:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' \
		${WRKSRC}/bindings/Hamlib-pl.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Hamlib/Hamlib.so
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
