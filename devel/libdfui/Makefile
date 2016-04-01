# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	libdfui
PORTVERSION=	4.1.20060122
CATEGORIES=	devel
MASTER_SITES=	LOCAL/philip

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Abstract user interface protocol library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libaura3.so:devel/libaura

USES=	tar:bzip2
USE_LDCONFIG=	yes

SONAME=		${SOLINK}.4
SOLINK=		${PORTNAME}4.so

PLIST_FILES=	lib/${SONAME} \
		lib/${SOLINK} \
		include/dfui4/conn_caps.h \
		include/dfui4/conn_npipe.h \
		include/dfui4/conn_tcp.h \
		include/dfui4/dfui.h \
		include/dfui4/dump.h \
		include/dfui4/encoding.h \
		include/dfui4/lang.h \
		include/dfui4/system.h
PORTDOCS=	README

MAKE_ENV=	SONAME=${SONAME} SOLINK=${SOLINK}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${SONAME} ${STAGEDIR}${PREFIX}/lib/${SONAME}
	${LN} -s ${SONAME} ${STAGEDIR}${PREFIX}/lib/${SOLINK}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/dfui4
	${INSTALL_DATA} ${WRKSRC}/conn_caps.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/conn_npipe.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/conn_tcp.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/dfui.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/dump.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/encoding.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/lang.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/system.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
