# Created by: Thomas Gellekum <tg@freebsd.org>
# $FreeBSD$

PORTNAME=	asl
PORTVERSION=	1.41r8
CATEGORIES=	devel
MASTER_SITES=	SUNSITE/devel/lang/assemblers \
		ftp://john.ccac.rwth-aachen.de/pub/as/source/c_version/

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	Assembler for a variety of microcontrollers/-processors

ONLY_FOR_ARCHS=	i386 amd64

MAKE_ENV+=	STAGEDIR=${STAGEDIR}

post-extract:
	${CP} ${FILESDIR}/Makefile.def ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's/mkdirhier/mkdir \-p/' ${WRKSRC}/install.sh

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/asl
	${INSTALL_DATA} ${WRKSRC}/doc_EN/* ${STAGEDIR}${PREFIX}/share/doc/asl

.include <bsd.port.mk>
