# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libidn2
PORTVERSION=	0.14
CATEGORIES=	dns
MASTER_SITES=	GNU_ALPHA/libidn \
		https://ftp.iana.org/assignments/idna-tables-6.3.0/:idna_table \
		http://www.unicode.org/Public/6.3.0/ucd/:nfcqc \
		http://www.unicode.org/Public/idna/6.3.0/:test,tr64map \
		LOCAL/sunpoet/${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		idna-tables-6.3.0.txt:idna_table \
		DerivedNormalizationProps.txt:nfcqc \
		IdnaTest.txt:test \
		IdnaMappingTable.txt:tr64map
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of IDNA2008 internationalized domain names

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libunistring.so:devel/libunistring

CONFIGURE_ARGS=	--disable-nls \
		--with-libunistring-prefix=${LOCALBASE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		charsetfix gmake iconv libtool localbase perl5 shebangfix

INFO=		libidn2

SHEBANG_FILES=	gen-tables-from-iana.pl tests/gen-utc-test.pl

post-patch:
	@cd ${DISTDIR}/ && ${CP} idna-tables-6.3.0.txt IdnaMappingTable.txt DerivedNormalizationProps.txt ${WRKSRC}/
	@cd ${DISTDIR}/ && ${CP} IdnaTest.txt ${WRKSRC}/tests/

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/idn2_noinstall

.include <bsd.port.mk>
