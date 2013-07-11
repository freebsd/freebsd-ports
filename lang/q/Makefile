# Created by: ag@muwiinfa.geschichte.uni-mainz.de Albert Graef
# $FreeBSD$

PORTNAME=	q
PORTVERSION=	7.11
PORTREVISION=	13
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-lang/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Q -- equational programming language

DEPRECATED=	Q-Lang is no longer supported. See lang/pure instead
EXPIRATION_DATE=2013-08-10 

LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick \
    		curl:${PORTSDIR}/ftp/curl \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gdbm.4:${PORTSDIR}/databases/gdbm \
		gmp.10:${PORTSDIR}/math/gmp \
		iodbc.3:${PORTSDIR}/databases/libiodbc \
    		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		ggi.2:${PORTSDIR}/graphics/libggi

USES=		bison iconv
USE_GCC=	any
USE_TK=		84+
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-magick="`pkg-config ImageMagick --libs`" \
		--with-magick-includes="`pkg-config ImageMagick --cflags`" \
		--with-tk="-L${TK_LIBDIR} -L${TCL_LIBDIR} -ltk${TK_VER:S/.//} -ltcl${TCL_VER:S/.//}" \
		--with-tk-includes="-I${TK_INCLUDEDIR} -I${TCL_INCLUDEDIR}" \
		--with-gdbm="-L${LOCALBASE}/lib -lgdbm" \
		--with-gdbm-includes="-I${LOCALBASE}/include" \
		--with-curl="`curl-config --libs`" \
		--with-curl-includes="`curl-config --cflags`" \
		--with-gmp="-L${LOCALBASE}/lib -lgmp" \
		--with-gmp-includes="-I${LOCALBASE}/include" \
		--with-ggi="-L${LOCALBASE}/lib -lggi" \
		--with-ggi-includes="-I${LOCALBASE}/include" \
		--with-pthread="${PTHREAD_LIBS}" \
		--with-odbc="`iodbc-config --libs`" \
		--with-odbc-includes="`iodbc-config --cflags`"

MAN1=	q.1
INFO=	qdoc

.include <bsd.port.mk>
