# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	sunpinyin
DISTVERSION=	2.0.4rc2
CATEGORIES=	chinese devel
MASTER_SITES=	LOCAL/delphij:1 \
		${MASTER_SITE_GOOGLE_CODE}:1 \
		http://open-gram.googlecode.com/files/:2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1 \
		lm_sc.t3g.arpa.tar.bz2:2 dict.utf8.tar.bz2:2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	Statistical language model based input method engine

LICENSE=	LGPL21 CDDL
LICENSE_COMB=	dual

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

USE_XZ=		yes
USE_SCONS=	yes
SCONS_ARGS+=	--prefix=${PREFIX} --libdatadir=${PREFIX}/share
USE_LDCONFIG=	yes
USES=		gmake iconv pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

NO_STAGE=	yes
post-patch:
	@${CP} ${_DISTDIR}/lm_sc.t3g.arpa.tar.bz2 \
		${_DISTDIR}/dict.utf8.tar.bz2 ${WRKSRC}/raw

.include <bsd.port.mk>
