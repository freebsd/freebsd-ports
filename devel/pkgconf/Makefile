PORTNAME=	pkgconf
PORTVERSION=	2.3.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://distfiles.ariadne.space/${PORTNAME}/

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to help to configure compiler and linker flags
WWW=		https://gitea.treehouse.systems/ariadne/${PORTNAME}

LICENSE=	ISCL

TEST_DEPENDS=	kyua:devel/kyua

USES=		cpe tar:xz libtool pathfix
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
TEST_TARGET=	check
CONFIGURE_ARGS=	--with-pkg-config-dir=${PREFIX}/libdata/pkgconfig:/usr/libdata/pkgconfig:${PREFIX}/share/pkgconfig \
		--with-system-libdir=/usr/lib \
		--with-system-includedir=/usr/include

OPTIONS_DEFINE=	DOCS

TESTING_UNSAFE=	tests/Kyuafile:5: Non-existent test program 'tests/basic'

post-install:
	${LN} -sf pkgconf ${STAGEDIR}${PREFIX}/bin/pkg-config

.include <bsd.port.mk>
