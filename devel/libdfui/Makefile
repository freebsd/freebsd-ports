# New ports collection makefile for:   libdfui
# Date created:        18 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	libdfui
PORTVERSION=	4.1.20060122
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	philip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstract user interface protocol library

LIB_DEPENDS=	aura3.3:${PORTSDIR}/devel/libaura

USE_BZIP2=	yes
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
PLIST_DIRS=	include/dfui4
PORTDOCS=	README

MAKE_ENV=	SONAME=${SONAME} SOLINK=${SOLINK}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${SONAME} ${PREFIX}/lib/${SONAME}
	${LN} -s ${PREFIX}/lib/${SONAME} ${PREFIX}/lib/${SOLINK}
	${MKDIR} ${PREFIX}/include/dfui4
	${INSTALL_DATA} ${WRKSRC}/conn_caps.h ${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/conn_npipe.h ${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/conn_tcp.h ${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/dfui.h ${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/dump.h ${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/encoding.h ${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/lang.h ${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/system.h ${PREFIX}/include/dfui4/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
