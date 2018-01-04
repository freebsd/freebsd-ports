# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	sunpinyin
DISTVERSION=	2.0.4rc3
PORTREVISION=	1
CATEGORIES=	chinese devel
MASTER_SITES=	SF/open-gram:2
DISTFILES=	lm_sc.3gm.arpa-20140820.tar.bz2:2 dict.utf8-20131214.tar.bz2:2

MAINTAINER=	lichray@gmail.com
COMMENT=	Statistical language model based input method engine

LICENSE=	LGPL21 CDDL
LICENSE_COMB=	dual

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USE_GITHUB=	yes
GH_TAGNAME=	a8bd811

MAKE_ARGS+=	--prefix=${PREFIX}
USE_LDCONFIG=	yes
USES=		gmake iconv perl5 pkgconfig python:2.7 scons shebangfix
USE_PERL5=	build
SHEBANG_FILES=	python/*.py
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
INSTALL_TARGET=	install-lib install-headers --install-sandbox=${STAGEDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsunpinyin.so.3.0
	${SETENV} PATH=${WRKSRC}/src:$${PATH} ${GMAKE} -C ${WRKDIR} \
		-f ${WRKSRC}/src/sunpinyin-dictgen.mk STAGEDIR=${STAGEDIR}
	${INSTALL} -d ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/lm_sc.t3g ${WRKDIR}/pydict_sc.bin \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
