# Created by: ijliao
# $FreeBSD$

PORTNAME=	ftplib
PORTVERSION=	4.0
CATEGORIES=	ftp
MASTER_SITES=	http://nbpfaus.net/~pfau/ftplib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of routines that implement the FTP protocol

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes
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
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} qftp ${PREFIX}/bin)
.for i in ftpdir ftpget ftplist ftprm ftpsend
	(cd ${PREFIX}/bin && ${LN} -sf qftp ${i})
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} ftplib.h ${PREFIX}/include)
	(cd ${WRKSRC} && ${INSTALL_DATA} libftp.a libftp.so.4 ${PREFIX}/lib)
	(cd ${PREFIX}/lib && ${LN} -sf libftp.so.4 libftp.so)

.include <bsd.port.mk>
