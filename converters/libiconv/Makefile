PORTNAME=	libiconv
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	converters devel
MASTER_SITES=	GNU

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Character set conversion library
WWW=		https://www.gnu.org/software/libiconv/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-nls \
		--docdir=${DOCSDIR} \
		am_cv_func_iconv=no
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Include extra character sets

ENCODINGS_CONFIGURE_ENABLE=	extra-encodings

post-patch:
	@${REINPLACE_CMD} -e 's:ei_ksc5601:ei_euc_kr:g' ${WRKSRC}/lib/aliases.h
	@${REINPLACE_CMD} -e 's:gawk:awk:g' ${WRKSRC}/configure \
		${WRKSRC}/libcharset/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so

.include <bsd.port.mk>
