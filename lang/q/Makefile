# New ports collection makefile for:	q
# Date created:		14 August 2003
# Whom:			ag@muwiinfa.geschichte.uni-mainz.de Albert Graef
#
# $FreeBSD$
#

PORTNAME=	q
PORTVERSION=	7.11
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/q-lang

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Q -- equational programming language

LIB_DEPENDS=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick \
    		curl.5:${PORTSDIR}/ftp/curl \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		gmp.8:${PORTSDIR}/math/libgmp4 \
		iodbc.3:${PORTSDIR}/databases/libiodbc \
    		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		ggi.2:${PORTSDIR}/graphics/libggi

USE_BISON=	yes
USE_ICONV=	yes
USE_TK=		84
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
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
