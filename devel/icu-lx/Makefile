# $FreeBSD$

PORTEPOCH=	0 # don't bump
CATEGORIES?=	devel print
PKGNAMESUFFIX=	-lx

COMMENT=	ICU Paragraph Layout API

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libicu-le-hb.so:devel/icu-le-hb

MASTERDIR=	${.CURDIR}/../icu
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

USES=		pkgconfig
CONFIGURE_ARGS=	--enable-layoutex
INSTALL_WRKSRC=	${WRKSRC}/layoutex

.include "${MASTERDIR}/Makefile"
