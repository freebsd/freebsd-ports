PORTNAME=	trans
PORTVERSION=	1.20
CATEGORIES=	converters
MASTER_SITES=	http://www.kostis.net/freeware/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character encoding converter generator

LIBDIR=		${PREFIX}/lib/trans
MANS=		transhtm.1 transiso.1 transce8.1 transtab.1 checkiso.1 \
		checkuni.1

post-patch:
# Fix the build against arbitrary make(1) implementation
	@${REINPLACE_CMD} -e 's/cd src ; make/$$(MAKE) -C src/' \
		${WRKSRC}/Makefile
# Unbreak parallel builds (-jX): fix targets' dependencies
	@${REINPLACE_CMD} -e 's/loadtab\$$(OBJ)$$/$$(OBJLIB)/' \
		${WRKSRC}/src/Makefile

do-install:
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} ${MANS:R} ${STAGEDIR}${PREFIX}/bin
.for m in ${MANS}
	${INSTALL_MAN} ${WRKSRC}/src/${m:R}.man ${STAGEDIR}${MANPREFIX}/man/man1/${m}
.endfor
	@${MKDIR} ${STAGEDIR}${LIBDIR}/cedf ${STAGEDIR}${LIBDIR}/xlt \
		${STAGEDIR}${LIBDIR}/doc ${STAGEDIR}${LIBDIR}/bin \
		${STAGEDIR}${LIBDIR}/src
	cd ${WRKSRC}/src && \
		${INSTALL_SCRIPT} checkall chkuni mkhtml mklist mkxlt \
		${STAGEDIR}${LIBDIR}/src
	cd ${WRKSRC} && \
		${INSTALL_DATA} README encoding.lis ${STAGEDIR}${LIBDIR}
	cd ${WRKSRC}/src && \
		${INSTALL_DATA} datatype.h ${STAGEDIR}${LIBDIR}/src
	cd ${WRKSRC}/bin && \
		${INSTALL_DATA} one trans.[ch] trans.man utimbuf.h utf.[ch] \
		${STAGEDIR}${LIBDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/cedf/* ${STAGEDIR}${LIBDIR}/cedf
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${LIBDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/xlt/* ${STAGEDIR}${LIBDIR}/xlt

.include <bsd.port.mk>
