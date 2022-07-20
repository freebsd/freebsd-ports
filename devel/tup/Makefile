PORTNAME=	tup
PORTVERSION=	0.7.11
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES=	https://gittup.org/tup/releases/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast and smart file-based build system

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		fuse pkgconfig

DO_MAKE_BUILD=	${SETENV} ${MAKE_ENV} ${SH} bootstrap-nofuse.sh

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz \
		share/vim/vimfiles/syntax/${PORTNAME}.vim

post-patch:
	@${REINPLACE_CMD} -e 's,-Os,${CFLAGS},' ${WRKSRC}/Tuprules.tup

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${INSTALL_WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles/syntax
	${INSTALL_DATA} ${INSTALL_WRKSRC}/contrib/syntax/*.vim \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/syntax

.include <bsd.port.mk>
