# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hamsterdb
PORTVERSION=	2.1.11
PORTREVISION=	9
CATEGORIES=	databases
MASTER_SITES=	http://files.hamsterdb.com/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Lightweight Embedded Database Engine

LICENSE=	APACHE20

BROKEN_powerpc64=	fails to configure: checking for the Boost system library... no

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

USES=		alias gmake libtool
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-boost=${LOCALBASE}
INSTALL_TARGET=	install-strip
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

HAM_DOCS=	README INSTALL ChangeLog TODO AUTHORS CREDITS

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/unittests/Makefile.in
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/tools/ham_bench/Makefile.in
	${REINPLACE_CMD} -e '/^CXXFLAGS=$${CFLAGS}$$/d' ${WRKSRC}/configure

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${HAM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
