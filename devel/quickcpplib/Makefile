PORTNAME=	quickcpplib
DISTVERSION=	g20230614
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Eliminate hassle when making state-of-the-art C++14-23 libraries
WWW=		https://github.com/ned14/quickcpplib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/Licence.txt

BROKEN_i386=	complation fails: __int128 is not supported on this target

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	ned14
GH_TAGNAME=	f9ab259
GH_TUPLE=	\
		ned14:quickcpplib:af81e79226211640acace43637a929e4aae4b1f3:ned14_quickcpplib/doc/html \
		martinmoene:span-lite:dbb484f6c2060b41afa55653dec99b228013a813:martinmoene_span_lite/include/quickcpplib/span-lite \
		ned14:pcpp:2ad25f10d358d85dcb3c5dfc358980a6cd008165:ned14_pcpp/pcpp \
		akrzemi1:Optional:2b43315458a99fc5de1da6e7bc0ddd364b26d643:akrzemi1_Optional/include/quickcpplib/optional \
		martinmoene:byte-lite:5bf0d80352197a4fb3526ad678a23a4c0c40d094:martinmoene_byte_lite/include/quickcpplib/byte \
		ned14:ply:fbc7a3cbc6e57d18462453dc65ba2c985fd6ac21:ned14_ply/pcpp/pcpp/ply

LDFLAGS+=	-lrt

.include <bsd.port.mk>
