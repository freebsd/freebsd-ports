# Created by: jraynard
# $FreeBSD$

PORTNAME=	sfio
PORTVERSION=	1999
CATEGORIES=	devel
MASTER_SITES=	NETBSD
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.src.unix.cpio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Safe/Fast I/O Library

EXTRACT_CMD=	${CPIO}
EXTRACT_BEFORE_ARGS=	-idF
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

# Remove a test that's too clever for its own good
post-extract:
	@${MV} ${WRKSRC}/src/lib/sfio/Sfio_t/tmmap2read.c \
		${WRKSRC}/src/lib/sfio/Sfio_t/.tmmap2read.c

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100093
post-patch:
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' \
		${WRKSRC}/src/lib/sfio/*.[ch]
.endif

do-build:
	@cd ${WRKSRC}/src/lib/sfio && ${MAKE} all -f makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/sfio
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include/sfio
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} libsfio.a libstdio.a ${STAGEDIR}${PREFIX}/lib)
	${INSTALL_MAN} ${WRKSRC}/man/man1/iffe.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/sfio.3 ${STAGEDIR}${PREFIX}/man/man3

.include <bsd.port.post.mk>
