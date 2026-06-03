PORTNAME=	hivex
PORTVERSION=	1.3.24
CATEGORIES=	devel
MASTER_SITES=	https://download.libguestfs.org/hivex/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing Windows Registry hive files
WWW=		https://libguestfs.org/hivex.3.html \
		https://github.com/libguestfs/hivex

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext-runtime gmake gnome iconv libtool perl5 pkgconfig readline shebangfix
USE_GNOME=	libxml2
USE_PERL5=	build

CONFIGURE_ARGS=	--disable-nls \
		--disable-ocaml \
		--disable-ruby \
		--with-readline \
		${CONFIGURE_ARGS_${ARCH}}
CONFIGURE_ARGS_amd64=	--enable-year2038
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	sh/hivexget
bash_CMD=	/bin/sh

OPTIONS_DEFINE=	PERL PYTHON
OPTIONS_DEFAULT=PERL PYTHON
OPTIONS_SUB=	yes

PERL_BUILD_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy
PERL_CONFIGURE_ENABLE=	perl
PERL_RUN_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy
PERL_USE=		PERL5=run
PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python

post-install-PERL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Win/Hivex/Hivex.so

.include <bsd.port.mk>
