PORTNAME=	kconfig-frontends
DISTVERSION=	4.11.0.1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/nuttx/tools/downloads/

MAINTAINER=	tomek@cedro.info
COMMENT=	Kconfig files parser and frontend
WWW=		https://bitbucket.org/nuttx/tools/downloads/

LICENSE=	GPLv2

USES=		gmake gperf libtool python shebangfix tar:bz2 ncurses
SHEBANG_FILES=	utils/kconfig-diff utils/kconfig-tweak.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gconf --disable-qconf --enable-mconf --enable-mconf
INSTALL_TARGET=	install-strip
DOCS=		AUTHORS COPYING README docs/kconfig-language.txt \
		docs/kconfig.txt

.include <bsd.port.options.mk>

post-install:
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
