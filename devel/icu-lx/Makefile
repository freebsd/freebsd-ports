PORTEPOCH=	0 # don't bump
CATEGORIES?=	devel print
PKGNAMESUFFIX=	-lx

COMMENT=	ICU Paragraph Layout API

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libicu-le-hb.so:devel/icu-le-hb

USES=		pkgconfig

CONFIGURE_ARGS=	--enable-layoutex
INSTALL_WRKSRC=	${WRKSRC}/layoutex

MASTERDIR=	${.CURDIR}/../icu
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
