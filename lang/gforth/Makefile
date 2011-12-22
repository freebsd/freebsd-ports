# New ports collection makefile for:	gforth
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gforth
PORTVERSION=	0.7.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gforth

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Fast and portable Forth system

LIB_DEPENDS=	ffi:${PORTSDIR}/devel/libffi
BUILD_DEPENDS=	${LOCALBASE}/include/avcall.h:${PORTSDIR}/devel/ffcall

BROKEN=		fails to build

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-fno-reorder-blocks -fno-inline
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool libltdl
USE_LDCONFIG=	${PREFIX}/lib/gforth/${PORTVERSION}/libcc-named
ALL_TARGET=	all info
MAKE_JOBS_UNSAFE=yes

STRIP=		#none

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		WORDSIZE=${WORDSIZE} BYTEORDER=${BYTEORDER}

DOC_FILES=	AUTHORS BUGS Benchres COPYING COPYING.DOC \
		INSTALL INSTALL.BINDIST NEWS README \
		NEWS.vmgen README.vmgen ToDo

MAN1=		gforth.1
INFO=		gforth vmgen
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == "powerpc"
WORDSIZE=32
.else
WORDSIZE=64
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BYTEORDER=b
.else
BYTEORDER=l
.endif

post-patch:
	${REINPLACE_CMD} 's:@CC@:& -I${LOCALBASE}/include -L${LOCALBASE}/lib:' \
		 ${WRKSRC}/envos.fs.in

post-install: install-doc remove-empty-files remove-empty-dirs

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for filename in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${filename} ${DOCSDIR}
.endfor
.endif

# Remove unused file
remove-empty-files:
	@${RM} -f ${DATADIR}/site-forth/siteinit.fs

# Remove unused directories
remove-empty-dirs:
	@${FIND} -d ${DATADIR}/${PORTVERSION}/arch/ -type d -empty -delete

.include <bsd.port.post.mk>
