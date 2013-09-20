# Created by: Andrey A. Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trans
PORTVERSION=	1.20
CATEGORIES=	converters
MASTER_SITES=	http://www.kostis.net/freeware/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character encoding converter generator

LIBDIR=		${PREFIX}/lib/trans
MAN1=		transhtm.1 transiso.1 transce8.1 transtab.1 checkiso.1 \
		checkuni.1

NO_STAGE=	yes
post-patch:
# Fix the build against arbitrary make(1) implementation
	@${REINPLACE_CMD} -e 's/cd src ; make/$$(MAKE) -C src/' \
		${WRKSRC}/Makefile
# Unbreak parallel builds (-jX): fix targets' dependencies
	@${REINPLACE_CMD} -e 's/loadtab\$$(OBJ)$$/$$(OBJLIB)/' \
		${WRKSRC}/src/Makefile

do-install:
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} ${MAN1:R} ${PREFIX}/bin
.for m in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/src/${m:R}.man ${MANPREFIX}/man/man1/${m}
.endfor
	@${MKDIR} ${LIBDIR}/cedf ${LIBDIR}/xlt ${LIBDIR}/doc ${LIBDIR}/bin \
		${LIBDIR}/src
	cd ${WRKSRC}/src && \
		${INSTALL_SCRIPT} checkall chkuni mkhtml mklist mkxlt \
		${LIBDIR}/src
	cd ${WRKSRC} && \
		${INSTALL_DATA} README encoding.lis ${LIBDIR}
	cd ${WRKSRC}/src && \
		${INSTALL_DATA} datatype.h ${LIBDIR}/src
	cd ${WRKSRC}/bin && \
		${INSTALL_DATA} one trans.[ch] trans.man utimbuf.h utf.[ch] \
		${LIBDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/cedf/* ${LIBDIR}/cedf
	${INSTALL_DATA} ${WRKSRC}/doc/* ${LIBDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/xlt/* ${LIBDIR}/xlt

.include <bsd.port.mk>
