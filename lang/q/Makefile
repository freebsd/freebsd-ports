# New ports collection makefile for:	q
# Date created:		14 August 2003
# Whom:			ag@muwiinfa.geschichte.uni-mainz.de Albert Graef
#
# $FreeBSD$
#

PORTNAME=	q
PORTVERSION=	4.6
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	q-lang

MAINTAINER=	ag@muwiinfa.geschichte.uni-mainz.de
COMMENT=	Q -- equational programming language

BUILD_DEPENDS=	${LOCALBASE}/dx/lib_freebsd/libDXL.a:${PORTSDIR}/graphics/opendx
LIB_DEPENDS=	Magick.8:${PORTSDIR}/graphics/ImageMagick \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		gii.0:${PORTSDIR}/devel/libgii \
		ggi.2:${PORTSDIR}/graphics/libggi \
		gmp.6:${PORTSDIR}/math/libgmp4

BROKEN=		Does not compile

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GNOME=	gnometarget
CFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${LOCALBASE}/dx/lib_freebsd" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-dxl-includes=-I${LOCALBASE}/dx/include
INSTALLS_SHLIB=	yes

# The tk module is built by default, but you can disable this by defining
# the following variable.
.if defined(WITHOUT_TK)
CONFIGURE_ARGS+=	--without-tk
.else
LIB_DEPENDS+=	tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84
CFLAGS+=	-I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4
CONFIGURE_ARGS+=	--with-tk="-ltcl84 -ltk84"
.endif

# POSIX threads support is enabled by default, but you can disable this by
# defining the following variable.
.if defined(WITHOUT_PTHREAD)
CONFIGURE_ARGS+=	--without-pthread
.else
CONFIGURE_ARGS+=	--with-pthread="${PTHREAD_LIBS}"
.endif

# The odbc module needs an ODBC driver manager to be installed, and it
# supports both iODBC and unixODBC. The following variable may be set at
# build-time to either "iodbc" or "unixodbc", with the former being the
# default:
ODBC?=		iodbc

.if ${ODBC} == "unixodbc"
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=-lodbc
.else	# assume we're using iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-odbc=-liodbc
.endif

MAN1=	q.1
INFO=	qdoc

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 (shared libraries must be compiled with -fPIC)"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/*info*

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${GREP} -l "^examplesdir" | ${XARGS} ${REINPLACE_CMD} -e \
		"s;[(]pkgdatadir[)]/examples;(datadir)/examples/@PACKAGE@;"
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} \
		${GREP} -l "<malloc\.h>" | ${XARGS} ${REINPLACE_CMD} \
		-e "s,<malloc\.h>,<stdlib.h>,"

.include <bsd.port.post.mk>
