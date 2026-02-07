PORTNAME=	hamlib
DISTVERSION=	4.6.5
CATEGORIES=	comms hamradio
MASTER_SITES=	SF

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications
WWW=		https://sourceforge.net/projects/hamlib/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	swig:devel/swig

USES=		autoreconf gnome libtool:keepla localbase:ldflags perl5 \
		pkgconfig python readline shebangfix tcl
USE_LDCONFIG=	yes
USE_PERL5=	build run
USE_PYTHON=	py3kplist

# $TCL_INCLUDE_SPEC
SHEBANG_FILES=	bindings/perltest.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libusb \
		--with-perl-binding \
		--with-python-binding \
		--with-tcl-binding \
		--with-tcl=${TCL_LIBDIR}
CONFIGURE_ENV=	cf_with_cxx=yes \
		LIBUSB_LIBS="-lusb"

INSTALL_TARGET=	install-strip

PLIST_SUB=	TCL_VER=${TCL_VER}
PORTDOCS=	AUTHORS COPYING* ChangeLog INSTALL LICENSE NEWS PLAN README* THANKS

OPTIONS_DEFINE=	DOCS STATIC
OPTIONS_SUB=	yes

STATIC_CONFIGURE_ENABLE=	static

post-build:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' \
		${WRKSRC}/bindings/Hamlib-pl.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Hamlib/Hamlib.so

post-install-DOCS-on:
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-off:
# Upstream scripts install some of the ${PORTDOCS} by default,
# so we need to remove the whole ${STAGEDIR}${DOCSDIR} explicitly.
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
