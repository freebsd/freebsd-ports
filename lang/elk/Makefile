PORTNAME=	elk
PORTVERSION=	3.99.8
PORTREVISION=	3
CATEGORIES=	lang scheme
MASTER_SITES=	http://sam.zoy.org/elk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeddable Scheme interpreter
WWW=		http://sam.zoy.org/projects/elk/

		#libelf.so:devel/libelf
LIB_DEPENDS=	libgdbm.so:databases/gdbm \
		libXaw.so:x11-toolkits/libXaw

USES=		libtool localbase:ldflags motif tar:bzip2 xorg
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xmu xt

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/libelf

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS=		-O0
.endif

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc examples||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/elk.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${STAGEDIR}${EXAMPLESDIR} --unlink -xf -
	@${FIND} ${STAGEDIR}${EXAMPLESDIR}/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;

.include <bsd.port.post.mk>
