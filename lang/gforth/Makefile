# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	gforth
PORTVERSION=	0.7.3
PORTREVISION=	12
CATEGORIES=	lang
MASTER_SITES=	http://www.complang.tuwien.ac.at/forth/gforth/ \
		GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast and portable Forth system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	Assertion failed: (pi->restlength >=0), function check_prims, file ./main.c, line 1049.
BROKEN_powerpc64=	fails to package: Unable to access file usr/local/share/gforth/0.7.3/kernl64l.fi:No such file or directory

LIB_DEPENDS=	libavcall.so:devel/libffcall \
		libffi.so:devel/libffi \
		libltdl.so:devel/libltdl

USES=		gmake libtool:build localbase makeinfo
USE_GCC=	any
USE_LDCONFIG=	${PREFIX}/lib/gforth/${PORTVERSION}/libcc-named

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GFORTHHIST=${WRKSRC}
MAKE_ENV=	GFORTHHIST=${WRKSRC}
ALL_TARGET=	kernel/version.fs more info
MAKE_JOBS_UNSAFE=yes

STRIP=		#none

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		WORDSIZE=${WORDSIZE} BYTEORDER=${BYTEORDER}

PORTDOCS=	AUTHORS BUGS Benchres COPYING COPYING.DOC \
		INSTALL INSTALL.BINDIST NEWS README \
		NEWS.vmgen README.vmgen ToDo

INFO=		gforth vmgen

OPTIONS_DEFINE=	DOCS

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
	${INSTALL_DATA} ${WRKSRC}/${filename} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

# Remove unused file
remove-empty-files:
	@${RM} ${STAGEDIR}${DATADIR}/site-forth/siteinit.fs

# Remove unused directories
remove-empty-dirs:
	@${FIND} -d ${STAGEDIR}${DATADIR}/${PORTVERSION}/arch/ -type d -empty -delete

.include <bsd.port.post.mk>
