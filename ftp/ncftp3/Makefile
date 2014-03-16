# Created by: ache
# $FreeBSD$

PORTNAME=	ncftp
PORTVERSION=	3.2.5
PORTREVISION?=	0
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/ \
		ftp://ftp.mirrorservice.org/sites/ftp.ncftp.com/ncftp/
DISTNAME=	ncftp-${PORTVERSION}-src

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	FTP client with advanced user interface

LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

USES=	tar:bzip2

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	LIBS DOCS
OPTIONS_DEFAULT=LIBS
LIBS_DESC=		Install optional libraries
OPTIONS_SUB=	yes

PORTDOCS=	*

LIBNCFTP=	libncftp.so.3
LIBSIO=		libsio.so.5
LIBSTRN=	libStrn.so.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBS}
pre-build:
.for dir in Strn libncftp sio
	${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -C ${WRKSRC}/${dir} so
.endfor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ncftpbatch ${STAGEDIR}${PREFIX}/bin/ncftpspooler
	${INSTALL_MAN} ${WRKSRC}/doc/man/* ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Strn/Strn.3 ${STAGEDIR}${MANPREFIX}/man/man3
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	-${RM} -r ${STAGEDIR}${DOCSDIR}/man

.if ${PORT_OPTIONS:MLIBS}
	${INSTALL_LIB} ${WRKSRC}/Strn/${LIBSTRN} ${STAGEDIR}${PREFIX}/lib
.for lib in libncftp/${LIBNCFTP} sio/${LIBSIO} Strn/${LIBSTRN}
	${INSTALL_LIB} ${WRKSRC}/${lib} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${lib:T} ${STAGEDIR}${PREFIX}/lib/${lib:T:R}
.endfor
.endif

.include <bsd.port.mk>
