# Created by: ijliao
# $FreeBSD$

PORTNAME=	ftplib
PORTVERSION=	4.0.1
CATEGORIES=	ftp
MASTER_SITES=	http://nbpfaus.net/~pfau/ftplib/
DISTNAME=	${PORTNAME}-4.0-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of routines that implement the FTP protocol

LICENSE=	ART20
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USES=		gmake
USE_LDCONFIG=	yes

PLIST_FILES=	bin/ftpdir bin/ftpget bin/ftplist bin/ftprm bin/ftpsend \
		bin/qftp include/ftplib.h \
		lib/libftp.a lib/libftp.so lib/libftp.so.4

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SOVERSION/s|=.*|= $$(SONAME)| ; \
		 s|CFLAGS =|CFLAGS +=| ; \
		 s|LDFLAGS =|LDFLAGS +=| ; \
		 s|$$(SOVERSION)|$$(SONAME)| ; \
		 s|-lc -o|-o| ; \
		 /libftp.so/s|ln -sf|${TRUE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qftp ${STAGEDIR}${PREFIX}/bin
.for i in ftpdir ftpget ftplist ftprm ftpsend
	${LN} -sf qftp ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/ftplib.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libftp.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libftp.so.4 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libftp.so.4 ${STAGEDIR}${PREFIX}/lib/libftp.so

.include <bsd.port.mk>
