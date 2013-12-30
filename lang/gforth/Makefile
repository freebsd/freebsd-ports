# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	gforth
PORTVERSION=	0.7.2
CATEGORIES=	lang
MASTER_SITES=	http://www.complang.tuwien.ac.at/forth/gforth/ \
		GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Fast and portable Forth system

LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi
BUILD_DEPENDS=	${LOCALBASE}/include/avcall.h:${PORTSDIR}/devel/ffcall

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-fno-reorder-blocks -fno-inline
USES=		gmake
USE_GCC=	any
USE_AUTOTOOLS=	libtool libltdl
USE_LDCONFIG=	${PREFIX}/lib/gforth/${PORTVERSION}/libcc-named
ALL_TARGET=	kernel/version.fs more info
MAKE_JOBS_UNSAFE=yes

STRIP=		#none

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		WORDSIZE=${WORDSIZE} BYTEORDER=${BYTEORDER}

PORTDOCS=	AUTHORS BUGS Benchres COPYING COPYING.DOC \
		INSTALL INSTALL.BINDIST NEWS README \
		NEWS.vmgen README.vmgen ToDo

INFO=		gforth vmgen

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc
WORDSIZE=32
.else
WORDSIZE=64
.endif

.if ${ARCH} == powerpc || ${ARCH} == sparc64
BYTEORDER=b
.else
BYTEORDER=l
.endif

post-patch:
	${REINPLACE_CMD} 's:@CC@:& -I${LOCALBASE}/include -L${LOCALBASE}/lib:' \
		 ${WRKSRC}/envos.fs.in
	${REINPLACE_CMD} '/ checkone/d' ${WRKSRC}/Makefile.in

post-install: install-doc remove-empty-files remove-empty-dirs

install-doc:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for filename in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${filename} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

# Remove unused file
remove-empty-files:
	@${RM} -f ${STAGEDIR}${DATADIR}/site-forth/siteinit.fs

# Remove unused directories
remove-empty-dirs:
	@${FIND} -d ${STAGEDIR}${DATADIR}/${PORTVERSION}/arch/ -type d -empty -delete

.include <bsd.port.post.mk>
