PORTNAME=	liborcus
DISTVERSION=	0.20.2
CATEGORIES=	devel misc
#MASTER_SITES=	https://kohei.us/files/orcus/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents
WWW=		https://gitlab.com/orcus/orcus

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mdds>=${MDDS_VERSION}:devel/mdds
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libixion-0.20.so:textproc/libixion

USES=		autoreconf compiler:c++17-lang gmake libtool localbase:ldflags \
		pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	orcus
GL_PROJECT=	orcus

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CXXFLAGS+=	-Wno-narrowing

CONFIGURE_ARGS=	--disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system \
		--disable-python

OPTIONS_DEFINE=	STATIC
OPTIONS_DEFAULT=STATIC
OPTIONS_SUB=	yes

STATIC_CONFIGURE_ENABLE=	static

PLIST_SUB=	VERSION=${PORTVERSION:R}

MDDS_VERSION=	3.1

post-patch:
	${REINPLACE_CMD} -e 's/mdds-3.0/mdds-${MDDS_VERSION}/' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
